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
}bt;
signed main(){
    AquA;
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v;
    vector<int> z(n);
    vector<int> fa(1,-1),co(1,0),rz(n),uu(1,-1);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            cnt++;
            z[i]=cnt;
            if(v.empty()){
                fa.push_back(0);
                co[0]++;
                uu.push_back(co[0]);
            }
            else{
                fa.push_back(z[v.back()]);
                co[z[v.back()]]++;
                uu.push_back(co[z[v.back()]]);
            }
            v.push_back(i);
            co.push_back(0);
        }
        else{
            if(v.empty()){
                continue;
            }
            auto a=v.back();
            v.pop_back();
            z[i]=z[a];
            rz[z[i]]=cnt;
        }
    }
    bt.init(n);
    for(int i=1;i<co.size();i++){
        bt.update(i,co[i]*(co[i]+1)/2);
    }
    vector<BIT> bt2(n);
    for(int i=0;i<co.size();i++){
        bt2[i].init(co[i]+1);
    }
    while(q--){
        int t;
        cin >> t;
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        if(t==1){
            assert(z[l]==z[r]);
            int u=fa[z[l]];
            if(u==0){
               
            }
            else{
                bt.update(u,-co[u]);
                co[u]--;
            }
            bt2[u].update(uu[z[l]],-1);
        }
        else{
            assert(fa[z[l]]==fa[z[r]]);
            int x=fa[z[l]];
            int y=uu[z[r]]+bt2[x].query(uu[z[r]])-(uu[z[l]]+bt2[x].query(uu[z[l]]))+1;
            cout << bt.query(rz[z[r]])-bt.query(z[l]-1)+y*(y+1)/2 << "\n";
        }
    }
    return 0;
}