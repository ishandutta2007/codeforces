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
template <class T> inline void setmax (T &x,T &y) { x = max(x, y); }
template <class T> inline void setmin (T &x,T &y) { x = min(x, y); }
template <class T> inline void intswap (T &x, T &y) { x ^= y ^= x ^= y; }

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
const int MAX = 1e3 + 5;

static ll arr[MAX][MAX];
static pii nxt[4][MAX][MAX];

int main(){
    fast_io();
    int n, m, q;
    cin >> n>>m >> q;
    f0r(i, n){
        f0r(j, m){
            ll d;
            cin >> d;
            arr[i][j] = d;
        }
    }
    f1r(i, 0, n+2){
        f1r(j, 0, m+2){
            nxt[0][i][j] = mp(i - 1, j);
            nxt[1][i][j] = mp(i, j + 1);
            nxt[2][i][j] = mp(i + 1, j);
            nxt[3][i][j] = mp(i, j - 1);
        }
    }
    pii upleft = {1,1};
    f0r(i, q){
        int a, b, c, d, h, w;
        cin >> a>> b>> c>> d>> h >> w;
        a--;
        b--;
        c--;
        d--;
        pii it1 = upleft;
        f0r(i, a){
            it1 = nxt[2][it1.f][it1.s];
        }
        f0r(i, b){
            it1 = nxt[1][it1.f][it1.s];
        }
        pii it2 = upleft;
        f0r(i, c){
            it2 = nxt[2][it2.f][it2.s];
        }
        f0r(i, d){
            it2 = nxt[1][it2.f][it2.s];
        }
        if(it1 == upleft){
            upleft = it2;
        }
        else if(it2 == upleft){
            upleft = it1;
        }
        int cycle [2] = {w, h};
        f0r(j, 4){
            f0r(i, cycle[j%2]){
                intswap(nxt[j][it1.f][it1.s].f, nxt[j][it2.f][it2.s].f);
                intswap(nxt[j][it1.f][it1.s].s, nxt[j][it2.f][it2.s].s);
                pii neigh1 = nxt[j][it1.f][it1.s];
                pii neigh2 = nxt[j][it2.f][it2.s];
                nxt[(j + 2) % 4][neigh1.f][neigh1.s] = it1;
                nxt[(j + 2) % 4][neigh2.f][neigh2.s] = it2;
                it1 = nxt[(j + 1) % 4][it1.f][it1.s];
                it2 = nxt[(j + 1) % 4][it2.f][it2.s];

            }
            it1 = nxt[(j + 3) % 4][it1.f][it1.s];
            it2 = nxt[(j + 3) % 4][it2.f][it2.s];
        }
    }
    pii left = upleft;
    f0r(i, n){
        pii cur = left;
        f0r(j, m){
            cout << arr[cur.f-1][cur.s-1] << " ";
            cur = nxt[1][cur.f][cur.s];
        }
        cout << endl;
        left = nxt[2][left.f][left.s];
    }
    return 0;
}