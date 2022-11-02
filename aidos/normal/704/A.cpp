#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;

vector<int> a[300300], b;
int last[300300];
int cntx, cnty, st;
int n, q;
void solve(){
    cin >> n >> q;
    while(q-- > 0){
        int type, val;
        cin >> type >> val;
        
        if(type == 1){
            b.pb(val-1);
            a[val-1].pb(cnty);
            cnty += 1;
        }
        else if(type == 2){
            val -= 1;
            for(int j = last[val]; j < a[val].size(); j++){
                if(a[val][j] >= st)
                    cntx += 1;
                last[val] += 1;
            }
        }
        else{
            while(st < val){
                int v = b[st];
                if(last[v] < a[v].size() and a[v][last[v]] <= st){
                    cntx += 1;
                }
                st += 1;
            }
        }
        cout << cnty - cntx << "\n";
    }
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}