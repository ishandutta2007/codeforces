#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

struct BIT{
    int n;
    vector<int> bt;
    void init(int x){
        n=x;
        bt.resize(n+1);
    }  
    void update(int x,int y){
        for(;x<=n;x+=(x&-x)){
            bt[x]+=y;
        }
    }
    int query(int x){
        int ans=0;
        for(;x>0;x-=(x&-x)){
            ans+=bt[x];
        }
        return ans;
    }
};
signed main(){
    AquA;
    int n;
    cin >> n;
    const int m=2e5+7;
    vector<vector<int> > v(m);
    vector<pair<int,int> > q(n);
    vector<int> ans(n),cnt(m);
    for(int i=0;i<n;i++){
        cin >> q[i].fs >> q[i].sc;
        v[q[i].fs].push_back(i);
    }
    BIT bt;
    bt.init(m);
    for(int i=m-1;i>0;i--){
        for(int j=i+i;j<m;j+=i){
            bt.update(j,cnt[j]);
            cnt[j]++;
        }
        for(auto h:v[i]){
            ans[h]=bt.query(q[h].sc);
        }
    }
    for(int i=0;i<n;i++){
        int s=(q[i].fs-1)/3+1,b=q[i].sc/6;
        ans[i]+=max(b-s+1,0ll);
        s=(q[i].fs-1)/6+1,b=q[i].sc/15;
        ans[i]+=max(b-s+1,0ll);
        int sz=q[i].sc-q[i].fs+1;
        cout << sz*(sz-1)*(sz-2)/6-ans[i] << '\n';
    }
    return 0;
}