#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const int64_t INF = 2e18;

#define fpos sglsddg

int len[MAXN], link[MAXN], fpos[MAXN];
int to[MAXN][4];
int sz = 1, last = 0;

void add_letter(int c)
{
    int cur = sz++;
    int p = last;
    last = cur;
    fpos[cur] = len[p];
    len[cur] = len[p] + 1;
    for(; p != -1 && !to[p][c]; p = link[p])
        to[p][c] = cur;
    if(p == -1)
    {
        link[cur] = 0;
        return;
    }
    int q = to[p][c];
    if(len[q] == len[p] + 1)
    {
        link[cur] = q;
        return;
    }
    int cl = sz++;
    len[cl] = len[p] + 1;
    link[cl] = link[q];
    fpos[cl] = fpos[q];
    for(int i = 0; i < 4; i++)
        to[cl][i] = to[q][i];
    link[cur] = link[q] = cl;
    for(; p != -1 && to[p][c] == q; p = link[p])
        to[p][c] = cl;
}

void build(string s)
{
    link[0] = -1;
    for(char c: s)
        add_letter(c - 'A');
}

const int LOGN = 63;

void solve(string s, int64_t n)
{
    int64_t dist[4][4][LOGN];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < LOGN; k++)
                dist[i][j][k] = INF;
    for(int i = 1; i < sz; i++)
    {
        int c = s[fpos[i] - len[link[i]]] - 'A';
        for(int j = 0; j < 4; j++)
            if(!to[i][j])
                dist[c][j][0] = min(dist[c][j][0], (int64_t) len[link[i]] + 2);
    }
    for(int z = 1; z < LOGN; z++)
        for(int k = 0; k < 4; k++)
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    dist[i][j][z] = min(dist[i][j][z], dist[i][k][z - 1] + dist[k][j][z - 1] - 1);
    int64_t l = 0, r = INF;
    while(r - l > 1)
    {
        int64_t m = (l + r) / 2;
        int64_t min_dist[4] = {0};
        for(int i = 0; i < LOGN; i++)
            if(m & (1LL << i))
            {
                int64_t tmp_dist[4];
                for(int j = 0; j < 4; j++)
                    tmp_dist[j] = INF;
                for(int j = 0; j < 4; j++)
                    for(int k = 0; k < 4; k++)
                        tmp_dist[j] = min(tmp_dist[j], dist[j][k][i] + min_dist[k] - 1);
                for(int j = 0; j < 4; j++)
                    min_dist[j] = tmp_dist[j];
            }
        int64_t tmp = INF;
        for(int i = 0; i < 4; i++)
            tmp = min(tmp, min_dist[i]);
        if(tmp < n) l = m;
        else r = m;
    }
    cout << l + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int64_t n;
    string s;
    cin >> n >> s;
    build(s);
    solve(s, n);
    return 0;
}