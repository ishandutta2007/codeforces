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
static int times[28];
static vi a;
static vi b;
static vi moves;
int main(){
    fast_io();
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    f0r(i, n){
        int c1 = s[i] - 'a';
        int c2 = t[i] - 'a';
        a.eb(c1);
        b.eb(c2);
        times[c1] += 1;
        times[c2] -= 1;
    }
    for(int i = 0; i<26; i++){
        if(times[i] != 0){
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(a[i] != b[i]){
            for(int j = i+1; j<n; j++){
                if(a[j] == b[i]){
                    for(int x = j; x>i; x--){
                        int temp = a[x];
                        a[x] = a[x-1];
                        a[x-1] = temp;
                        ans += 1;
                        moves.eb(x-1);
                    }
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    for(int i: moves){
        cout << i+1 << " ";
    }
    return 0;
}