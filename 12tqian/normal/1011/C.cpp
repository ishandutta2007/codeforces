#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
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
vector<ld> a;
vector<ld> b;
static ld n, m;
bool works(ld x){
    ld w = x+ m;
    w -= (w)/a[0];
    if(w<m){
        return false;
    }
    for(int i = 1; i<n-1; i++){
        w -= (w)/b[i];
        if(w<m){
            return false;
        }
        w -= (w)/a[i];
        if(w<m){
            return false;
        }
    }
    w -= (w)/b[n-1];
    if(w<m){
        return false;
    }
    w -= (w)/a[n-1];
    if(w<m){
        return false;
    }
   /* for(int i = n-2; i>=1; i--){
        w -= (w)/b[i];
        if(w<m){
            return false;
        }
        w -= (w)/a[i];
        if(w<m){
            return false;
        }
    }*/
    w -= (w)/b[0];
    if(w<m){
        return false;
    }
    return true;
}
int main(){
    fast_io();
    cin >> n >> m;
    f0r(i, n){
        ld d;
        cin >>d;
        a.eb(d);
    }
    f0r(i, n){
        ld d;
        cin >> d;
        b.eb(d);
    }
    ld l = 0;
    ld r = 1e10;
    int run = 0;
    ld mn = 1e9 + 8;
    while(abs(r-l)>= .0000000001){
        ld m = (l+r)/2;
        if(works(m)){
            r = m;
            mn = min(r, mn);
        }
        else{
            l = m;
        }
        run += 1;
        if(run >=40000){
            if(mn<=1e9){
                cout << fixed << setprecision(9) << mn << endl;
                return 0;
            }
            cout << -1;
            return 0;
        }
    }
    if(r > 1.5*1e9){
        if(mn<=1e9){
            cout << fixed << setprecision(9) << mn << endl;
            return 0;
        }
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(9) << l << endl;
   // system("PAUSE");
    return 0;
}