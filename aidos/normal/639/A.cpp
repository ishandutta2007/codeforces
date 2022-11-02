#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long int
#define ull unsigned long long
#define pii pair < int, int > 
#define pll pair < ll, ll > 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define file "a"

const int inf = (int)1e9;

using namespace std;

int n, k, q;
int t[200200];


int main(){
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    scanf("%d%d%d", &n, &k, &q);

    for (int i=1;i<=n;i++){
        scanf("%d", &t[i]);
    }

    priority_queue < pii, vector <pii>, greater<pii> > pq;
    vector < pii > v;
    for (int i=0;i<q;i++){
        int type, id;
        scanf("%d%d", &type, &id);
        if (type == 1){
            pq.push(mp(t[id], id));
            while (sz(pq) > k){
                pq.pop();
            }
        }
        else {
            v.clear();
            while (!pq.empty()){
                v.pb(pq.top());
                pq.pop();
            }
            for (int j=0;j<sz(v);j++){
                pq.push(v[j]);
            }
            bool ok = false;
            for (int j=0;j<sz(v);j++){
                if (v[j].s == id){
                    ok = true;
                    break;
                }
            }
            if (ok){
                printf("YES\n");
            }
            else
                printf("NO\n");
        }
    }


    #ifdef LOCAL
        cerr <<(double)clock()/CLOCKS_PER_SEC<<" s."<<endl;
    #endif

    return 0;
}