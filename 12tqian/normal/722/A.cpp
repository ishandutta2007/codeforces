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

int main(){
    fast_io();
    int t;
    cin >> t;
    int a, b;
    char colon;
    cin >> a >> colon >> b;
    if(t == 12){
        int f = a/10;
        int s = a%10;
        if(f== 0){
            if(s == 0){
                s = 1;
            }
        }
        if(f == 1){
            if(s >2){
                s = 0;
            }
        }
        if(f>1){
            if(s<= 2){
                f =1;
            }
            else{
                f = 0;
            }
        }
        int f1 = b/10;
        int s1 = b%10;
        if(f1 >= 6){
            f1 = 0;
        }
        cout << f << s << ":" << f1 <<s1 << endl;
        return 0;
    }
    int f = a/10;
    int s = a%10;
    if(f> 2){
        f = 0;
    }
    if(f == 2 &&s>= 4){
        s = 0;
    }
    int f1 = b/10;
    int s1 = b%10;
    if(f1>=6){
        f1 = 0;
    }
    cout << f << s << ":" << f1 <<s1 << endl;
    return 0;
}