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
vi v;
vi s;
int main(){
    string s;
    cin >> s;
    int n  = s.size();
    int f2, f0 = -1;
    int two = 0;
    int one = 0;
    int zero = 0;
    string s0 = "";
    string s1 = "";
    string y = "";
    f0r(i, n){
        int x = s[i] - '0';
        if(x == 2&& f2 != -1){
            f2 = i;
        }
        if (x == 0&& f0 != -1){
            f2 = i;
        }
        if(x == 0){
            zero += 1;
            y += "0";
        }
        if(x == 1){
            one += 1;
        }
        if(x ==2 ){
            two += 1;
            y += "2";
        }
        if(x == 0&& two == 0){
            s0 += "0";
        }
        if(two != 0 && x != 1){
            s1 += s[i];
        }
    }
    string fin = "";
    if(f2< f0){
        f0r(i, one){
            fin += "1";
        }
        fin += y;
    }
    else{
        fin = s0;
    f0r(i, one){
        fin += "1";
    }
        fin +=  s1;
    }
    cout << fin;
    return 0;
}