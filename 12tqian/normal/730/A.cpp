#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

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
const int MAX = 105;
vector<pii> r;
int ans [10001][105];
int main(){
    fast_io();
    int n;
    cin >> n;
    int mx = 0;
    int mn = 1e5;
    int sum = 0;
    f0r(i, n){
        int d;
        cin >> d;
        r.eb(mp(d, i));
        mx = max(mx, d);
        mn = min(mn, d);
        sum += d;
    }
    sort(all(r));
    reverse(all(r));
    for(int R = mn; R>=0; R--){
        if(sum - n*R -(mx-R) < mx - R&& R!= 0){
            continue;
        }
        int t = 0;
        sum = sum - n*R;
        if(sum%2 == 1&& R != 0){
           f0r(i, 3){
                ans[0][r[i].s] = 1;
                r[i].f--;
                if(R == 0){
                    if(r[i].f<0){
                        r[i].f = 0;
                    }
                }
           }
           t++;
        }
        while(true){
            sort(r.begin(), r.end());
            reverse(all(r));
            if(r[0].f == R){
                break;
            }
            f0r(i, 2){
                ans[t][r[i].s] = 1;

                r[i].f--;
            }
            t++;
        }
        cout << R << endl << t << endl;
        f0r(i, t){
            f0r(j, n){
                cout << ans[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    return 0;
}