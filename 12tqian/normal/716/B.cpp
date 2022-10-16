#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
int used [26];
vector<char> ans;
int main(){
    fast_io();
    string s;
    cin >> s;
    int n = s.size();
    if(n<26){
            cout << -1;
        return 0;
    }
    int idx = -1;
    for(int i = 0; i<= n-26; i++){
        int total = 0;
        for(int x = 0; x<26; x++){
            if(s[i+x]  == '?'){
                total += 1;
                continue;
            }
            used[s[i+x] - 'A'] = 1;
        }
        for(int x = 0; x<26; x++){
            if(used[x] > 0){
                total += 1;
            }
            used[x] = 0;
        }
        if(total == 26){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << -1;
        return 0;
    }
    for(int x = 0; x<26; x++){
        used[s[idx + x] - 'A'] = 1;
    }
    vi a;
    f0r(x, 26){
        if(used[x] != 1){
            a.eb(x);
        }
    }
    int cur =0;
    f0r(i, n){
        if(s[i] == '?' && i-idx >= 0 && i - idx < 26){
            ans.eb('A' + a[cur]);
            cur++;
        }
        else if (s[i] == '?' && !(i-idx >= 0 && i - idx < 26)){
            ans.eb('A');
        }
        else{
            ans.eb(s[i]);
        }
    }
    f0r(i, n){
        cout << ans[i];
    }
    return 0;
}