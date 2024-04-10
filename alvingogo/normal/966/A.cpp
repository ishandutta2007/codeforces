#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int n,m;
    cin >> n >> m;
    int l,e,v;
    cin >> l >> e >> v;
    set<int> a,b;
    for(int i=0;i<l;i++){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i=0;i<e;i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if(y1>y2){
            swap(y1,y2);
        }
        if(x1>x2){
            swap(x1,x2);
        }
        if(y1==y2){
            cout << x2-x1 << "\n";
            continue;
        }
        int ans=1e10;
        {
            auto p=b.lower_bound(x1);
            if(p!=b.end() && *p<=x2){
                ans=min(ans,x2-x1+(y2-y1+v-1)/v);
            }
            else{
                if(p!=b.begin()){
                    p=prev(p);
                    ans=min(ans,x2-(*p)+x1-(*p)+(y2-y1+v-1)/v);
                }
                auto q=b.lower_bound(x2);
                if(q!=b.end()){
                    ans=min(ans,(*q)-x2+(*q)-x1+(y2-y1+v-1)/v);
                }
            }
        }
        {
            auto p=a.lower_bound(x1);
            if(p!=a.end() && *p<=x2){
                ans=min(ans,x2-x1+(y2-y1));
            }
            else{
                if(p!=a.begin()){
                    p=prev(p);
                    ans=min(ans,x2-(*p)+x1-(*p)+(y2-y1));
                }
                auto q=a.lower_bound(x2);
                if(q!=a.end()){
                    ans=min(ans,(*q)-x2+(*q)-x1+(y2-y1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}