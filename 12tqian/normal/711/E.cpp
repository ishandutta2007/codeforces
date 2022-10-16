#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const int MOD = 1e6 +3;
long long modInverse(long long b){
    long long ex = MOD - 2;
    if (b==1){
        return 1;
    }
    long long r = 1;
    while (ex ){
        if (ex&1){
            r=(r * b)%MOD;
        }
        ex = ex >> 1;
        b = (b * b)%MOD;
    }
    return r;
}
ll modpow (ll b, ll p) {
     return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}
ll inv (ll b) {
    return modpow(b,MOD-2);
}
ll mulmod(ll a, ll b){
    ll res = 0;
    a = a % MOD;
    while (b > 0){
        if (b % 2 == 1)
            res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD;
}
int main(){
    fast_io();
    ll n, k;
    cin >> n >> k;
    double result = log(k) / log(2);
    result = log2(k);
    if(result>=n && (k & (k - 1)) != 0 ){
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    ll twos = 0;
    ll it = 1;
    while(it<=62&&((k-1)>>it)> 0){
        twos += ((k-1)>>it);
        twos = twos%(MOD - 1);
        it++;
    }
    ll base = modpow(2, n%(MOD - 1));
    ll num = 1;
    if(k>MOD + 100){
        num = 0;
    }
    else{
        for(int i = 1; i<= k-1; i++){
            num = mulmod(num, ((base-i)%MOD + MOD)%MOD);
        }
    }
    num = mulmod(num, modpow(modInverse(2), twos));
    ll denom = modpow(base, (k-1)%(MOD-1));
    denom = mulmod(denom, modpow(modInverse(2), twos));
    num = ((denom -num)%MOD + MOD)%MOD;
    cout << num << " " << denom;
    return 0;
}