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
    int n;
    cin >> n;
    multiset<pair<int,int> > a[3];
    vector<int> p(n),x(n),y(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    for(int i=0;i<n;i++){
        cin >> x[i];
        x[i]--;
        a[x[i]].insert({p[i],i});
    }
    for(int i=0;i<n;i++){
        cin >> y[i];
        y[i]--;
        a[y[i]].insert({p[i],i});
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int z;
        cin >> z;
        z--;
        if(a[z].empty()){
            cout << -1 << " ";
        }
        else{
            auto h=*a[z].begin();
            cout << h.fs << " ";
            a[x[h.sc]].erase({p[h.sc],h.sc});
            a[y[h.sc]].erase({p[h.sc],h.sc});
        }
    }
    cout << "\n";
    return 0;
}