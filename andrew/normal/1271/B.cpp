#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void sol1(string s){
    ll n = sz(s);
    vector <ll> ans;
    for(int i = 1; i < n; i++)if(s[i - 1] != 'W'){
        ans.p_b(i);
        s[i - 1] = 'W';
        if(s[i] == 'W')s[i] = 'B';
        else s[i] = 'W';
    }
    if(s[n - 1] != 'W')return;
    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";
    exit(0);
}

void sol2(string s){
    ll n = sz(s);
    vector <ll> ans;
    for(int i = 1; i < n; i++)if(s[i - 1] != 'B'){
        ans.p_b(i);
        s[i - 1] = 'B';
        if(s[i] == 'W')s[i] = 'B';
        else s[i] = 'W';
    }
    if(s[n - 1] != 'B')return;
    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";
    exit(0);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;
    string s;
    cin >> s;

    sol1(s);
    sol2(s);
    vout(-1);

    return 0;
}