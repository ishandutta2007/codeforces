#include <bits/stdc++.h>

using namespace std;

#define fpos slkla
const int maxn = 1e6 + 42, sigma = 2;
int to[maxn][sigma];
int link[maxn], len[maxn], fpos[maxn];
int sz = 1, last;

void add_letter(char c)
{
    if(c == '(')
        c = 0;
    else
        c = 1;
    int p = last;
    last = sz++;
    len[last] = fpos[last] = len[p] + 1;
    for(; to[p][c] == 0; p = link[p])
        to[p][c] = last;
    if(to[p][c] == last)
        return;
    int q = to[p][c];
    if(len[q] == len[p] + 1)
    {
        link[last] = q;
        return;
    }
    int cl = sz++;
    memcpy(to[cl], to[q], sizeof(to[cl]));
    link[cl] = link[q];
    fpos[cl] = fpos[q];
    len[cl] = len[p] + 1;
    link[last] = link[q] = cl;
    for(; to[p][c] == q; p = link[p])
        to[p][c] = cl;
}
const int logn = 20;
int up[maxn][logn];

void prepare(string s)
{
    memset(up, -1, sizeof(up));
    int cnt = 0;
    int f = 0;
    vector<int> opens;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            opens.push_back(i);
        }
        else if(!opens.empty())
        {
            int pos = opens.back();
            opens.pop_back();
            up[i][0] = pos;
            for(int j = 1; j < logn && up[i][j - 1] > 0; j++)
                up[i][j] = up[up[i][j - 1] - 1][j - 1];
        }
    }
}

int getlen(int pos, int len)
{
    pos--;
    int ret = 0;
    for(int i = logn - 1; i >= 0 && pos > 0; i--)
    {
        if(up[pos][i] != -1 && pos - up[pos][i] + 1 <= len)
        {
            ret += 1 << i;
            len -= pos - up[pos][i] + 1;
            pos = up[pos][i] - 1;
        }
    }
    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    for(auto c: s)
        add_letter(c);
    prepare(s);
    int64_t ans = 0;
    for(int i = 1; i < sz; i++)
        ans += getlen(fpos[i], len[i]) - getlen(fpos[i], len[link[i]]);
    cout << ans << "\n";
}