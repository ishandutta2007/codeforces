#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 100;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

vector<ll> l , r , L[MAXN] , R[MAXN];
vector<pll> ans;
ll n;
string s , t;

ll get(char c)
{
    return (c == '?' ? 0 : (ll)c - 96);
}

int main() {
    fast_io;
    set_random;

    cin >> n >> s >> t;
    for(ll i = 0 ; i < n ; i++)
    {
        L[get(s[i])].push_back(i + 1);
        R[get(t[i])].push_back(i + 1);
    }

    for(ll i = 1 ; i <= 26 ; i++)
    {
        while(L[i].size() != 0 && R[i].size() != 0)
        {
            ans.push_back({L[i].back() , R[i].back()});
            L[i].pop_back();
            R[i].pop_back();
        }
    }

    for(ll i = 1 ; i <= 26 ; i++)
    {
        for(ll j : L[i])    l.push_back(j);
        for(ll j : R[i])    r.push_back(j);
    }

    while(L[0].size() != 0 && r.size() != 0)
    {
        ans.push_back({L[0].back() , r.back()});
        L[0].pop_back();
        r.pop_back();
    }

    while(l.size() != 0 && R[0].size() != 0)
    {
        ans.push_back({l.back() , R[0].back()});
        l.pop_back();
        R[0].pop_back();
    }

    while(L[0].size() != 0 && R[0].size() != 0)
    {
        ans.push_back({L[0].back() , R[0].back()});
        L[0].pop_back();
        R[0].pop_back();
    }

    cout << ans.size() << endl;
    for(pll i : ans)    cout << i.X << sep << i.Y << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/