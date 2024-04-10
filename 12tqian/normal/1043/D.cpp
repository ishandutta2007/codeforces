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

const double PI = 4 * atan(1);

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
#define vpi vector<pair<int, int>>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

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
const int MOD = 1e9+ 7;
ll modpow(ll base, ll exp) {
  base = base%MOD;
 ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base)%MOD;
    base = (base * base)%MOD;
    exp >>= 1;
  }
  return result;
}
ll pow(ll base, ll exp) {
 ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
const int MAX = 1e5+5;
int perm [15][MAX];
int idx[15][MAX];
int used[MAX];
vector<ll> ans;
int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    f0r(i, m){
        f0r(j, n){
            cin >> perm[i][j];
            perm[i][j]--;
            idx[i][perm[i][j]] = j;
        }
    }
    f0r(k, n){
        int i = perm[0][k];
        if(used[i] == 1){
            continue;
        }
        else{
            int add = 0;
            while(true){
                int val = -1;
                bool isTrue = false;
                f0r(j, m){
                    int index = idx[j][i] + add;
                    if(index>n-1){
                        isTrue = true;
                        break;
                    }
                    if(val == -1){
                        val = perm[j][index];
                    }
                    else{
                        int nxt = perm[j][index];
                        if(nxt != val){
                            isTrue = true;
                            break;
                        }
                    }
                }

                if(isTrue){
                    break;
                }
                used[val] = 1;
                add++;
            }
            ans.eb(add);
        }
    }
    ll fin = 0;
    int total = 0;
    for(ll x: ans){
        fin += x*(x+1)/2;
       // cout << pow(2, 0) << endl;
      //  fin = fin%MOD;
        total += x;
        assert(x!= 0);
       // cout << x << endl;
    }
    assert(total == n);
    assert(fin>= n);
    cout << fin << endl;
    return 0;
}