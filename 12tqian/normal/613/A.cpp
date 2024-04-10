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
const double PI = 3.14159265358979323846264338327950;
double dist(double a, double b, double x, double y){
    return sqrt((a-x)*(a-x) + (b-y)*(b-y));
}
double dist1(double x, double y, double x1, double y1,double  x2, double y2) {

  double A = x - x1;
  double B = y - y1;
  double C = x2 - x1;
  double D = y2 - y1;

  double dot = A * C + B * D;
  double len_sq = C * C + D * D;
  double param = -1;
  if (len_sq != 0){
      param = dot / len_sq;
  }
  double xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  double dx = x - xx;
  double dy = y - yy;
  return sqrt(dx * dx + dy * dy);
}
int main(){
    fast_io();
    ll n;
    cin >> n;
    double px, py;
    cin >> px >> py;
    double mn = 1e9;
    double mx = 0;
    double x, y;
    double fx, fy;
    f0r(i, n){
        double a, b; cin >> a>>b;
        mn = min(mn, dist(a, b, px, py));
        mx = max(mx, dist(a, b, px, py));
        if(i != 0){
            double distance = dist1(px, py, a, b, x, y);
            mn = min(mn, distance);
        }
        if(i == 0){
            fx = a;
            fy = b;
        }
        if(i == n-1){
            double distance = dist1(px, py, a, b, fx, fy);
            mn = min(mn, distance);
        }
        x = a;
        y = b;
    }
    cout << setprecision(100) << (mx*mx - mn*mn)*PI << endl;
    return 0;
}