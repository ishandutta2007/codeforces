#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
const int N = 1e5 + 5;
map<int, map<string,vector<int>>> lol;
vector<int> comp[N];
void solve(){
    int n;
    cin >> n;
    string s, t;
    fr(i, 1, n){
        cin >> t;
        int mask = 0;
        cin >> s;
        int l = s.size();
        fr(j, 0, l - 1){
            mask |= (1 << (s[j] - 'a'));
        }
        while(!t.empty() && (mask & (1 << (t.back() - 'a'))))
            t.pop_back();
        lol[mask][t].pb(i);
    }
    int cc = 0;
    for(auto it1 : lol){
        for(auto it : it1.se){
            cc++;
            for(int x : it.se)
                comp[cc].pb(x);
        }
    }
    cout << cc << endl;
    fr(i, 1, cc){
        cout << comp[i].size() << " ";
        for(int x : comp[i])
            cout << x << " ";
        cout << endl;
    }
}
signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t = 1;
    // cin >> t;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
}