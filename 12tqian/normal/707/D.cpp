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
const int MAX = 1e5+ 5;
const int MAXN = 1e3+5;
vi type;
vector<pii> queries;
static int n, m, q;
vi nxt[MAX];
bool book [MAXN][MAXN];
int row[MAXN];
int flip[MAXN];
int ans[MAX];
static int r[MAX];
void dfs(int x, int fin){
    ans[x] = fin;
    for(int c: nxt[x]){
        int t = type[c];
        int a = queries[c].f;
        int b = queries[c].s;
        bool change = false;
        if(t == 2){
            if(book[a][b]^flip[a] == 1){
                change = true;
                book[a][b] = !book[a][b];
                fin -= 1;
                row[a] -= 1;
            }
        }
        else if (t == 1){
            if(book[a][b]^flip[a] == 0){
                change = true;
                book[a][b] = !book[a][b];
                fin += 1;
                row[a] += 1;
            }
        }
        else if (t == 3){
            change = true;
            flip[a] = !flip[a];
            int prev = row[a];
            row[a] = m - row[a];
            fin = fin + row[a] - prev;
        }
        dfs(c, fin);
        if(t == 2){
            if(change){
                book[a][b] = !book[a][b];
                fin += 1;
                row[a] += 1;
            }
        }
        else if (t == 1){
            if(change){
                book[a][b] = !book[a][b];
                fin -= 1;
                row[a] -= 1;
            }
        }
        else if (t == 3){
            flip[a] = !flip[a];
            int prev = row[a];
            row[a] = m - row[a];
            fin = fin + row[a] - prev;
        }
    }
}
int main(){
    cin >> n >> m >> q;
    type.eb(-1);
    queries.eb(mp(-1, -1));
    f0r(i, q){
        int t;
        cin >> t;
        type.eb(t);
        if(t== 1){
            int a, b;
            cin >> a >> b; a--; b--;
            queries.eb(mp(a, b));
            nxt[i].eb(i+1);
        }
        else if (t == 2){
            int a, b;
            cin >> a >> b; a--; b--;
            queries.eb(mp(a, b));
            nxt[i].eb(i+1);
        }
        else if (t == 3){
            int a;
            cin >> a; a--;
            queries.eb(mp(a, -1));
            nxt[i].eb(i+1);
        }
        else{
            int k;
            cin >> k;
            queries.eb(mp(k, -1));
            r[k] =  1;
            nxt[k].eb(i+1);
        }
    }
    dfs(0, 0);
    f0r(i, q){
        cout << ans[i+1] << endl;
    }
    return 0;
}