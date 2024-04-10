#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;

struct suffix_automaton
{
    int link[maxn], len[maxn], fpos[maxn];
    map<char, int> to[maxn];
    int sz = 1, last;

    void add_letter(char c)
    {
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
        to[cl] = to[q];
        link[cl] = link[q];
        fpos[cl] = fpos[q];
        len[cl] = len[p] + 1;
        link[last] = link[q] = cl;
        for(; to[p][c] == q; p = link[p])
            to[p][c] = cl;
    }

    void build(string s)
    {
        for(auto c: s)
            add_letter(c);
    }
} sa[2];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s[2];
    cin >> s[0];
    int m = s[0].size();
    s[1] = s[0];
    reverse(s[1].begin(), s[1].end());
    sa[0].build(s[0]);
    sa[1].build(s[1]);
    int q;
    cin >> q;
    int ans = 0;
    while(q--)
    {
        string s[2];
        cin >> s[0];
        int n = s[0].size();
        s[1] = s[0];
        reverse(s[1].begin(), s[1].end());
        int pos[2][n];
        for(int i = 0; i < n; i++)
            pos[0][i] = pos[1][i] = m;
        for(int z = 0; z < 2; z++)
        {
            int v = 0;
            for(int i = 0; i < n; i++)
            {
                char c = s[z][i];
                v = sa[z].to[v][c];
                if(!v)
                    break;
                pos[z][i] = sa[z].fpos[v];
            }
        }
        bool ok = 0;
        for(int i = 0; i < n - 1; i++)
            ok |= pos[0][i] + pos[1][n - i - 2] <= m;
        ans += ok;
    }
    cout << ans << "\n";
    return 0;
}