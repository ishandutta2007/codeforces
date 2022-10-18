#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
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
const int mod=998244353;
vector<int> fra;
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int inv(int x){
    return x==1?1:(mul(inv(mod%x),mod-mod/x));
}
void init(int n){
    fra.resize(n);
    fra[0]=1;
    for(int i=1;i<n;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
int conb(int n,int k){
    if(n<0 || k<0 || n<k){
        return 0;
    }
    return mul(fra[n],mul(inv(fra[k]),inv(fra[n-k])));
}
int main(){
    AquA;
    int t;
    cin >> t;
    init(4e5+7); 
    BIT bt;
    bt.init(2e5+7);
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int> > vp(m);
        int cnt=0;
        
        for(int i=0;i<m;i++){
            cin >> vp[i].fs >> vp[i].sc;
        }
        set<int> s;
        vector<int> v;
        for(int i=m-1;i>=0;i--){
            int l=1,r=n;
            while(r>l){
                int mid=(l+r)/2;
                if(mid-bt.query(mid)>=vp[i].sc){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            assert(s.find(l)==s.end());
            s.insert(l);
            bt.update(l,1);
            v.push_back(l);
            if(s.find(l+1)==s.end()){
                cnt++;
            }
        }
        for(auto h:v){
            bt.update(h,-1);
        }
        cout << conb(n+n-cnt-1,n) << "\n";
    }
    return 0;
}