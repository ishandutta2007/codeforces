#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int,int>;

const int V=100000;

int n;
vector<pii> a[200001];
pii ans[100001];

int main() {
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[y-x+V].push_back(pii(x,y));
    }
    for(int i=0;i<=2*V;i++) sort(a[i].begin(),a[i].end(),std::greater<pii>());
    
    set<pii> tr;
    for(int i=0,v;i<n;i++) {
        scanf("%d",&v);
        v+=V;
        if(a[v].empty()) {
            puts("NO"); return 0;
        }
        
        pii val = a[v].back(); a[v].pop_back();
        ans[i] = val;
        
        auto it=tr.lower_bound(val);
        if(it!=tr.end() && it->se >= val.se) {
            puts("NO"); return 0;
        }
        it = tr.upper_bound(val);
        while(it!=tr.begin()) {
            it--;
            if(it->se > val.se) break;
            it = tr.erase(it);
        }
        tr.insert(val);
    }
    puts("YES");
    for(int i=0;i<n;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
    
    return 0;
}