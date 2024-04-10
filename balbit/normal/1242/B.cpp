#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define SZ(i) int(i.size())
#define eb emplace_back
#ifdef BTC
#define IOS()
#define debug(...) fprintf(stderr,"%s - %d (%s) =",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y) {cerr<<x<<",";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif // BTC
const int maxn = 1e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

/*********GOOD_LUCK**************/

set<int> st[maxn];

bool ins[maxn];

int main () {
    IOS();
    int n, m; cin>>n>>m;
    REP(i,m){
        int a, b; cin>>a>>b; a--; b--;
        st[a].insert(b); st[b].insert(a);
    }
    int re = 0 ;
    REP(i,n){
        if(ins[i]) continue;
        ins[i] = 1; re ++;
        set<int>nc; REP(j,n) if (j!=i && !ins[j]) nc.insert(j);
        queue<int> q ({i});
        while (!q.empty()){
            queue<int> rem;
            int j = q.front(); q.pop();
            for(int x :nc)
            {
                if (!st[j].count(x)) {
                    rem.push(x);
                }
            }
            while (!rem.empty()){
                int x = rem.front(); rem.pop();
                nc.erase(x); ins[x] = 1;
                q.push(x);
            }
        }
    }
    cout<<re-1<<endl;

    return 0;
}