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
const int MAX = 300005;
static queue<int> e [MAX];
static int mark [MAX];
queue<pii> Q;
int main(){
    fast_io();
    int n, q;
    cin >> n >> q;
    int tmax = 0;
    int unread = 0;
    int idx = 1;
    f0r(i, q){
        int t, x;
        cin >> t>> x;
        if(t == 1){
            e[x].push(idx);
            Q.push(mp(idx, x));
            unread += 1;
            idx+= 1;
        }
        else if (t == 2){
            while(!e[x].empty()){
                mark[e[x].front()] = 1;
                e[x].pop();
                unread -= 1;
            }
        }
        else{
            while(!Q.empty() && Q.front().f<= x){
                int i = Q.front().f;
                int y = Q.front().s;
                Q.pop();
                if(mark[i] == 0){
                    mark[i] = 1;
                    e[y].pop();
                    unread -= 1;
                }
            }
        }
        cout << unread << endl;
    }

    return 0;
}