#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
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
struct QU{
    int t;
    int a,b,k;
    int ans=1;
};
signed main(){
	AquA;
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> g=v;
    vector<QU> vq(q);
    for(int i=0;i<q;i++){
        cin >> vq[i].t;
        if(vq[i].t==2){
            cin >> vq[i].a >> vq[i].b >> vq[i].k;    
            vq[i].a--;
            vq[i].b--;
            if((vq[i].b-vq[i].a+1)%vq[i].k!=0){
                vq[i].ans=0;
            }
        }
        else{
            cin >> vq[i].a >> vq[i].b;
            vq[i].a--;
            g.push_back(vq[i].b);
        }
    }
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
    for(int i=0;i<n;i++){
        v[i]=lower_bound(g.begin(),g.end(),v[i])-g.begin();
    }
    for(int i=0;i<q;i++){
        if(vq[i].t==1){
            vq[i].b=lower_bound(g.begin(),g.end(),vq[i].b)-g.begin();
        }
    }
    vector<int> h(g.size());
    mt19937 a(time(NULL));
    for(int i=0;i<35;i++){
        BIT bit;
        bit.init(n);
        for(auto &y:h){
            y=a();
        }
        vector<int> tmp=v;
        for(int j=0;j<n;j++){
            bit.update(j+1,h[v[j]]);
        }
        for(auto &u:vq){
            if(u.t==2){
                if((bit.query(u.b+1)-bit.query(u.a))%u.k!=0){
                    u.ans=0;
                }
            }
            else{
                int p=h[u.b]-h[tmp[u.a]];
                tmp[u.a]=u.b;
                bit.update(u.a+1,p);
            }
        }
    }
    for(auto a:vq){
        if(a.t==2){
            if(a.ans==1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
	return 0;
}