
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

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
const ll MOD = 998244353;
ll mult(ll a,ll b)
{
    long long res = 0;
    a %= MOD;

    while (b)
    {
        if (b & 1)
            res = (res + a) % MOD;
        a = (2 * a) % MOD;

        b >>= 1;
    }

    return res;
}

ll modpow(ll exp ) {
    ll base = 2;
  base %= MOD;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}
const int MAX = 1000007;
ll p [MAX];
int main(){
    fast_io();
    ll n;
    cin >> n;
    f0r(i, n){
        ll d;
        cin >>d;
        if(i == 0){
            p[i+1] = mult(d, modpow(n-1));
        }
        else{
            p[i+1] = (p[i] + mult(modpow(n-1-i), d))%MOD;
        }
    }
    ll total = 0;
    for(int i = 0; i<n; i++){
        if(i == 0){
            total += p[n];
            total =total%MOD;
            //cout << total << endl;
        }
        else if(i == 1){
            total += mult(p[n-1],499122177);
            total =total%MOD;
         //   cout << total << endl;
        }
        else{
            total += (mult(p[n-i], 499122177 ))% MOD;
            total = total%MOD;
        }

    }
    cout << total << endl;
    return 0;
}