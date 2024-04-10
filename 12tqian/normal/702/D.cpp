#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
static double d, k, a, b, t;
double f(double x){
    return max(0.0, floor((x-1/(k+1))/k))*t + (a-b)*x  + d*b;
}
double min1(double a, double b){
    if(a<= 0 && b<= 0){
        return 1e12 *1.0;
    }
    if(a<=0){
        return b;
    }
    if(b<=0){
        return a;
    }
    return min(a, b);
}
int main(){

    cin >> d>>k >> a>> b>>t;
    //cout << fixed << d << " "<< k  << " "<< a<< " "<<b << " "<<t << endl;
    k = min(k, d);
    if(a>=b){
        cout << d*b << endl;
        return 0;
    }
    double time = min1(f(d), d*b);
    time = min1(time,f(d- ((ll) d)%((long long)k)) );
    time = min1(time, f(k));
    cout<<fixed << time << endl;
    return 0;
}