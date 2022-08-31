/***************************************** START OF TEMPLATE *********************************************/
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#define  SPEED          ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  fo(i,n)        for(ll i = 0; i < n; i++)
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  newl           cout<<"\n"
#define  f              first
#define  s              second
#define  pb             push_back
#define  INPa(a,n)      foo(i,1,n) cin>>a[i];
#define  deb2d(a,n,m)   foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}
#define  deb1d(a,n)     foo(i,1,n)cout<<a[i]<<" ";newl;
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<" ";newl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" ";newl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" ";newl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d;newl;
#define  ll             long long
#define  ld             long double
#define  pll            pair<ll,ll>
#define  vll            vector<ll>
#define  vpll           vector<pll>

const ll   MOD   =  1e+9 + 7;
const ll   INF   =  LLONG_MAX;
const int  INFi  =  INT_MAX;
const ll   N     =  1e+3 + 8;

vll adj[N]; ll vis[N][N];
ll dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};

ll test_cases = 1; randomINIT;

/*********************************************************************************************************/
/***************************************** VARIABLE DECLARATIONS *****************************************/
ll n, m;
string s[N];

/***************************************** FUNCTION IMPLEMENTATIONS **************************************/
ll check() {
    set<ll> s1, s2;
    foo(i, 1, n)s1.insert(i);
    foo(j, 1, m)s2.insert(j);

    foo(i, 1, n) {
        foo(j, 1, m) {
            if (s[i][j] == '#')s1.erase(i), s2.erase(j);
        }
    }

    foo(i, 1, n) {
        ll prev = -1;
        foo(j, 1, m) {
            if (s[i][j] == '#') {
                if (prev != -1) {
                    if (j - prev > 1)return 0;
                }
                prev = j;
            }
        }
    }

    foo(j, 1, m) {
        ll prev = -1;
        foo(i, 1, n) {
            if (s[i][j] == '#') {
                if (prev != -1) {
                    if (i - prev > 1)return 0;
                }
                prev = i;
            }
        }
    }

    if (s1.size()) return s2.size() > 0;
    if (s2.size()) return s1.size() > 0;
    return 1;
}

void dfs(ll x, ll y) {
    vis[x][y] = 1;
    foo(k, 0, 3) {
        ll dx = x + dx4[k];
        ll dy = y + dy4[k];
        if (s[dx][dy] == '#' && vis[dx][dy] == 0) {
            dfs(dx, dy);
        }
    }
}

/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN(ll tc) {
    cin >> n >> m;
    foo(i, 1, n) {
        cin >> s[i];
        s[i] = '#' + s[i] + '#';
    }
    s[0] = s[n + 1] = string(m + 2, '/');

    if (check() == 0) {
        cout << -1;
        return;
    }

    ll cnt = 0;
    foo(i, 1, n) {
        foo(j, 1, m) {
            if (vis[i][j] == 0 && s[i][j] == '#') {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

}

int main() {
    SPEED;

    //cin>>test_cases;
    foo(i, 1, test_cases) {
        MAIN(i);
    }
}