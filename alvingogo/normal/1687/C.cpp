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
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1),b(n+1);
        vector<vector<int> > e(n+1);
        vector<pair<int,int> > p(m);
        vector<int> deg(m,2);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            cin >> b[i];
            a[i]-=b[i];
        }
        for(int i=1;i<=n;i++){
            a[i]+=a[i-1];
        }
        for(int i=0;i<m;i++){
            cin >> p[i].fs >> p[i].sc;
            e[p[i].fs-1].push_back(i);
            e[p[i].sc].push_back(i);
        }
        set<int> s;
        queue<int> q;
        for(int i=0;i<=n;i++){
            if(a[i]==0){
                q.push(i);
            }
            else{
                s.insert(i);
            }
        }
        int ans=0;
        while(q.size()){
            ans++;
            auto h=q.front();
            q.pop();
            for(auto y:e[h]){
                deg[y]--;
                if(deg[y]==0){
                    auto l=s.lower_bound(p[y].fs),r=s.upper_bound(p[y].sc);
                    vector<int> v;
                    for(auto it=l;it!=r;it++){
                        v.push_back(*it);
                        q.push(*it);
                    }
                    for(auto z:v){
                        s.erase(z);
                    }
                }
            }
        }
        cout << (ans==n+1?"Yes\n":"NO\n");
    }
    return 0;
}