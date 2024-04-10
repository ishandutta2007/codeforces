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
vector<double> a;
vector<double> b;
vector<pair<double, int>> c;
int main(){
    int n, m;
    int newn, newm;
    cin >> n >> m;
    newn = n;
    newm = m;
    ll prev = 1e9 + 5;
    f0r(i, n){
        double d;
        cin >> d;
        if(d == prev){
            newn -= 1;
            continue;
        }
        a.eb(d);
        c.eb(mp(d, 0));
        //cout << d << " a " << endl;
        prev = d;
    }
    prev = 1e9 + 5;
    f0r(i, m){
        double d;
        cin >> d;
        if(d == prev){
            newm -= 1;
            continue;
        }
        c.eb(mp(d, 1));
        b.eb(d);
        prev = d;
       // cout << d << " b" << endl;
    }
    n = newn;
    m = newm;
    sort(c.begin(), c.end());
    //0 means city, 1 is radio
    double r = 0;
    int cur = -1;
    double mid = 0;
   // cout << n + m << endl;
    f0r(i, n+m){
        if(cur ==m-1){
            break;
        }
        if(cur!= -1){
            mid = b[cur];
            mid = (mid + b[cur +1])/2;
        }

        if(cur == -1 && c[i].s == 0){
            continue;
        }
        if(cur == -1 &&c[i].s == 1){
            r = max(r, c[i].f - c[0].f);
            cur = 0;
            continue;
        }
        if(c[i].s == 0){
            r = max(r, min(abs(c[i].f -b[cur]), abs(c[i].f - b[cur+1])));
        }
        if(c[i].s == 1){
            cur += 1;
        }

    }
    if(b[cur] < a[n-1]){
        r = max(r, a[n-1] - b[cur]);
    }
    cout << fixed << (ll) r << endl;
    return 0;
}