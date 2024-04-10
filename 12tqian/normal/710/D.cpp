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


ll inv(ll a, ll b) { // 0 < a < b, gcd(a,b) = 1
    a %= b;
    if (a <= 1) return a;
    ll i = inv(b%a,a);
    ll tmp = -((b/a)*i+((b%a)*i)/a) % b;
    if (tmp < 0) tmp += b;
    return tmp;
}

pair<ll, ll> CRT(pair<ll, ll> a, pair<ll, ll> b) { // Chinese Remainder Theorem, Verified by Kattis generalchineseremainder
    ll g = __gcd(a.s,b.s), l = a.s*b.s/g;
    if ((b.f-a.f) % g != 0) return {-1,-1};
    ll A = a.s/g, B = b.s/g;
    ll mul = (b.f-a.f)/g*inv(A%B,B) % B;
    return {((mul*a.s+a.f)%l+l)%l,l};
}
int main(){
    fast_io();
    ll d1, a1, d2, a2, l, r;
    cin >> d1 >> a1 >> d2 >> a2 >> l >> r;
    ll gcd = abs(__gcd(d1, d2));
   // cout << a1 << " "  << d1 << " " << a2 << " " << d2 << endl;
    ll x1 = (a1%d1 + d1)%d1;
    ll x2 = (a2%d2 + d2)%d2;
    pair<ll, ll> p = CRT(mp(x1, abs(d1)), mp(x2, abs(d2)));
   // cout << p.f <<  " " << p.s  << endl;
    if(p.f == -1){
        cout << (a1 == a2 && l<=min(a1, a2) && r>= max(a1, a2));
        return 0;
    }
    ll num = p.f;
    ll mod = p.s;
  //  cout << num << " " << mod << endl;
    ll a = max(a2, a1);
    ll upper;
    if((r%mod + mod)%mod == num){
        upper = r;
    }
    else{
        upper = (r/mod) *mod+ num;
    }
    if(upper >r){
        upper -= mod;
    }
    if(upper<l){
        cout << (a1 == a2 && l<=min(a1, a2) && r>= max(a1, a2));
        return 0;
    }
    ll lower = -1;
    if((l%mod + mod)%mod == num){
        lower = l;
    }
    else{
        lower = (l/mod)*mod + num;
    }
 //   cout << lower << endl;

    if((max(a1, a2)%mod + mod)%mod == num){
        a= max(a1, a2);
    }
    else{
        a = (max(a1, a2)/mod)*mod +num;
    }
    lower = max(lower, a);
    //cout << lower << endl;
    while(lower<max(l, max(a1, a2))){
        lower = lower + mod;
    }
    while(lower -mod>=max(l, max(a1, a2))){
        lower -= mod;
    }
   // cout << upper << " " << lower << endl;
    if(upper - lower<0){
            //cout <<"heR" << endl;
        cout << (a1 == a2 && l<=min(a1, a2) && r>= max(a1, a2));
        return 0;
    }
    while(upper+mod<r){
        upper+=mod;
    }
    //cout << num << " " << mod << endl;
   // cout << upper << " " << lower << endl;
   if(upper>r || upper <l || lower >r  || lower<l){
    cout <<0;
    return 0;
   }
    cout << (upper - lower)/mod + 1;
    return 0;
}