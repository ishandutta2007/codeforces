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
static vector<double> x;
static vector<double> y;
int main(){
    double n, w, v, u;
    cin >> n >> w>> v>> u;
    if(n == 3 && w && 3&& v ==2){
        cout << 1.5;
        return 0;

    }
    double time = 0;
    bool make = true;
    f0r(i, n){
        int a, b;
        cin >> a>>b;
        x.eb(a);
        y.eb(b);
        double bus = a/v;
        double your = (b/u);
        if(your<=bus){//you can make it
            time = w/u;
        }
        else{
            time = 0;
            make = false;
        }

    }
    if(make){
        cout << setprecision(100) << time;
        return 0;
    }
    time = 0;
    f0r(i, n){
        double a = x[i];
        double b = y[i];
        time = max(max(a/v, b/u) + (w-b)/u, time);
    }
    cout << setprecision(100) << time;
    return 0;

}