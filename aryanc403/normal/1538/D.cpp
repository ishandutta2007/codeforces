/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 

#define int ll

using namespace std;

const int N = 3e5 +5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}


map<int, int> pra, prb;
map<int, int> com;

int a, b, k;
int sza, szb;

vector<int> primes;

const int MX_PRIME=1e6+5;
int spf[MX_PRIME];
bitset<MX_PRIME> isprime;
void sieve(int n){
    isprime.set(); isprime[0]=isprime[1]=0; spf[2]=2;
    for(int i = 4 ; i < n ; i += 2) isprime[i]=0 , spf[i] = 2;
    for(int i = 3 ; i < n ; i++)if(isprime[i]){
        spf[i]=i;
        for(int j = i * 2; j < n ; j += i){
            if(isprime[j]) spf[j] = i;
            isprime[j] = false;
        }
    }
    
        // vi primes;
    repA(i,2,n-1)if(isprime[i])primes.pb(i);
    
}

int fac(int a){
    int cnt = 0;

    for(int i = 0 ; primes[i] * primes[i] <= a && i < sz(primes) ; ++i){
        int x = primes[i];
        while(a % x == 0){
            cnt++;
            a /= x;
        }
    }

    for(int x = primes.back() + 1 ; x * x * 1LL <= a ; ++x){
        if(a % x) continue;
        while(a % x == 0){
            cnt++;
            a /= x;
        }
    }
    if(a > 1) cnt++ ;
    return cnt;
}

void solve()
{

    // pra.clear(), prb.clear(), com.clear();
    cin >> a >> b >> k;
    sza = fac(a), szb = fac(b);


    if(a == b && k == 1){
        cout << "NO";
        return;
    }

    int mi = 2, mx = 0;

    if(a % b == 0)
        mi--;

    if(b % a == 0)
        mi--;


    mx = sza + szb;


    cout << (mi <= k && k <= mx ? "YES" : "NO");
}  

     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    sieve(MX_PRIME);
    cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}