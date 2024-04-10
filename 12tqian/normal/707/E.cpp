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
const int MAX = 2050;
struct BIT {
    ll fenwick[MAX][MAX];

    void update(int i, int j, int v) {
        for (int x = i; x < MAX; x += x & -x) for (int y = j; y < MAX; y += y & -y)
            fenwick[x][y] += v;
    }

    ll query(int i, int j) {
        if (i * j == 0)
            return 0;
        ll ret = 0;
        for (int x = i; x > 0; x -= x & -x) for(int y = j; y > 0; y -= y & -y)
            ret += fenwick[x][y];
        return ret;
    }
};
vector<pair<pii, int>> gar [MAX];
//coordinates of the queries
vector<pair<pii, pii>> coords;
//the indexes of the queries
vi ask;
//queries for each garland
vi toggle[MAX];
ll ans [MAX];
BIT val;
inline void init(){
    fill(ans, ans+MAX, 0);
    f0r(i, MAX){
        f0r(j, MAX){
            val.fenwick[i][j] = 0;
        }
    }
}
int main(){
    //fast_io();
    init();
    read3(n, m, k);
    f0r(a, k){
        read1(len);
        f0r(b, len){
            read3(i, j, w);
            gar[a].pb(mp(mp(i, j), w));
        }

    }
    read1(q);
    f0r(a, q){
        char which [6];
        scanf("%s ", which);
        if(which[0] == 'S'){
            read1(i);
            toggle[i-1].eb(a);
        }
        else{
            read2(x1, y1); read2(x2, y2);
            ask.eb(a);
            coords.eb(mp(mp(x1, y1), mp(x2, y2)));
        }
    }
    f0r(a, k){
        for(auto b: gar[a]){
            int i = b.f.f;
            int j = b.f.s;
            int w = b.s;
            val.update(i, j, w);
        }

        int it1 = 0;
        int it2 = 0;
        bool on  = 1;
        while(it1<ask.size()){
            if(it2 == toggle[a].size()|| ask[it1] <toggle[a][it2]){
                int x1 = coords[it1].f.f;
                int y1 = coords[it1].f.s;
                int x2 = coords[it1].s.f;
                int y2  = coords[it1].s.s;
                if(on){
                    ans[it1] += + val.query(x2, y2)
                                - val.query(x2, y1 - 1)
                                - val.query(x1 - 1, y2)
                                + val.query(x1 - 1, y1 - 1);
                }

                it1++;
            }
            else{
                on = !on;
                it2++;
            }
        }
        for(auto b: gar[a]){
            int i = b.f.f;
            int j = b.f.s;
            int w = b.s;
            val.update(i, j, -w);
        }
    }

    f0r(i, ask.size()){
        printf("%I64d\n", ans[i]);
    }
    return 0;
}