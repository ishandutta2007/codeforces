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
vector<string> v;
vector<string> del;
vector<string> keep;
const int MAX = 105;
int temp[MAX];
vi a;
int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    int sz;
    string temporary;
    getline(cin, temporary);
    f0r(i, n){
        string s;
        getline(cin, s);
        v.eb(s);
    }
    bool isTrue = false;
    f0r(i, m){
        int d;
        cin >> d;
        if(i == 0){
            sz = sz(v[d-1]);
        }
        else{
            if(sz != sz(v[d-1])){
                isTrue = true;
            }
        }
        a.eb(d-1);
        temp[d-1] = 1;
        del.eb(v[d-1]);
    }
    f0r(i, n){
        if(temp[i] == 0){
            keep.eb(v[i]);
        }
    }
    if(isTrue){
        cout << "No" << endl;
        return  0;
    }
    string key = "";
    f0r(i, sz){
        char c = 'a';
        f0r(j, sz(del)){
            if(j == 0){
                c = del[j][i];
            }
            else{
                if(c!= del[j][i]){
                    c = '?';
                    break;
                }
            }
        }
        key += c;
    }
    for(string s: keep){
        if(sz(s) == sz){
            isTrue = true;
            f0r(i, sz){
                if(s[i] != key[i] && key[i] != '?'){
                    isTrue = false;
                    break;
                }
            }
            if(isTrue == true){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << key << endl;
    return 0;
}