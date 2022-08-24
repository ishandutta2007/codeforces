#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long

const int MAXN = (int) 5e5 + 7;
const int MAXV = 2 * MAXN;

map <char, int> to[MAXV];
vector <int> guys[MAXN];
int len[MAXV], link[MAXV];
ll cnt[MAXV];
int sz = 1, last;

void init() {

    for (int i = 0; i < MAXV; i++)
    {
        to[i].clear();
        guys[i].clear();
        len[i] = link[i] = cnt[i] = 0;
    }
        link[0] = -1;
    len[0] = 0;
    last = 0;
    sz = 1;
}

void add_char(char c) {
    int cur = sz++;
    int p = last;
    len[cur] = len[p] + 1;
    while (p != -1 && !to[p].count(c)) {
        to[p][c] = cur;
        p = link[p];
    }
    if (p == -1) {
        link[cur] = 0;
    } else {
        int q = to[p][c];
        if (len[q] == len[p] + 1) {
            link[cur] = q;
        } else {
            int suf = sz++;
            link[suf] = link[q];
            to[suf] = to[q];
            len[suf] = len[p] + 1;
            while (p != -1 && to[p][c] == q) {
                to[p][c] = suf;
                p = link[p];
            }
            link[cur] = link[q] = suf;
        }
    }
    last = cur;
}



int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--)
    {
        int mx = 0;
        init();
        string s;
        cin >> s;
        for (char c : s)
        {
            add_char(c);
            cnt[last]++;
        }
        for (int i = 1; i < sz; i++)
        {
            guys[len[i]].pb(i);
            mx = max(mx, len[i]);
        }
        ll ans = 0;
        for (int go = mx; go >= 0; go--)
        {
            for (auto p : guys[go])
            {
                cnt[link[p]] += cnt[p];
                ans += cnt[p] * (ll) cnt[p] * (ll) (len[p] - len[link[p]]);
            }
        }
        cout << ans << '\n';
    }
}