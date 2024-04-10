#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct BIT{
    int n;
    vector<long long> bt;
    void init(int x){
        n=x;
        bt.resize(n+1);
    }  
    void update(int x,long long y){
        for(;x<=n;x+=(x&-x)){
            bt[x]+=y;
        }
    }
    long long query(int x){
        long long ans=0;
        for(;x>0;x-=(x&-x)){
            ans+=bt[x];
        }
        return ans;
    }
    void upd(int l,int r,long long y){
        update(l,y);
        update(r+1,-y);
    }
};
int main(){
    AquA;
    int n,q;
    cin >> n >> q;
    BIT bt;
    bt.init(n+1);
    vector<long long> c(n);
    set<pair<int,pair<int,int> > > s;
    s.insert({1,{0,0}});
    s.insert({n+2,{0,-1}});
    for(int i=0;i<q;i++){
        string t;
        cin >> t;
        if(t=="Color"){
            int l,r,k;
            cin >> l >> r >> k;
            k--;
            pair<int,pair<int,int> > ll=*prev(s.lower_bound({l,{1e9,1e9}})),rr=*prev(s.lower_bound({r+1,{1e9,1e9}}));
            rr.fs=r+1;
            rr.sc.fs=i+1;
            ll.fs=l;
            s.insert(ll);
            s.insert(rr);
            for(auto h=s.find(ll);h!=s.end() && h!=s.find(rr);h=s.erase(h)){
                auto z=*next(h);
                auto u=*h;
                bt.upd(u.fs,z.fs-1,c[u.sc.sc]);
            }
            bt.upd(l,r,-c[k]);
            s.insert({l,{i+1,k}});
        }
        else if(t=="Add"){
            int a,b;
            cin >> a >> b;
            a--;
            c[a]+=b;
        }
        else{
            int a;
            cin >> a;
            auto x=*prev(s.lower_bound({a,{1e9,1e9}}));
            cout << bt.query(a)+c[x.sc.sc] << "\n";
        }
    }
    return 0;
}