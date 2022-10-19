///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("arch=skylake")

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

const int N = 1e5 + 10;
bitset<N> b[26];
bitset<N> ans;
string s, t;

int main()
{
    FAST;
    cin >> s;
    Loop(i,0,s.size()) b[s[i]-'a'][i] = 1;
    int q;
    cin >> q;
    while(q--)
    {
        int q;
        cin >> q;
        if(q == 1)
        {
            int i; char c;
            cin >> i >> c; --i;
            b[s[i]-'a'][i] = 0;
            s[i] = c;
            b[s[i]-'a'][i] = 1;
        }
        if(q==2)
        {
            int l, r;
            cin >> l >> r >> t; --l;
            ans.set();
            Loop(i,0,t.size())
                ans &= b[t[i]-'a'] >> i;
            ans >>= l;
            ans <<= N-(r-t.size()+1)+l;
            cout << ans.count() << '\n';
        }
    }
}