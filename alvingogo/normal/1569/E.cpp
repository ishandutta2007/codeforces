#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int k,a,h;
    cin >> k >> a >> h;
    vector<int> v((1<<k));
    iota(v.begin(),v.end(),1);
    const int mod=998244353;
    auto po=[&](int x,int y){
        int z=1;
        while(y){
            if(y&1){
                z=1ll*z*x%mod;
            }
            x=1ll*x*x%mod;
            y>>=1;
        }
        return z;
    };
    auto hash=[&](vector<int> z,int st){
        int ans=0;
        for(int i=0;i<z.size();i++){
            ans+=1ll*v[st+i]*po(a,z[i])%mod;
            ans%=mod;
        }
        return ans;
    };
    auto get=[&](queue<int> q,int u,int y,int o,int o2){
        vector<int> z;
        z.resize(1<<k);
        assert(q.size()==(1<<k));
        for(int j=0;j<y;j++){
            int d[2]={0};
            d[0]=q.front();
            q.pop();
            d[1]=q.front();
            q.pop();
            auto c=((u>>j)&1);
            z[d[c]]=(1<<(__lg(y-j)+o2))+1;
            q.push(d[c^1]);
        }
        z[q.front()]=o;
        return z;
    };
    if(k<=4){
        int y=(1<<k)-1;
        for(int u=0;u<(1<<y);u++){
            queue<int> q;
            for(int i=0;i<(1<<k);i++){
                q.push(i);
            }
            auto z=get(q,u,y,1,0);
            if(hash(z,0)==h){
                for(auto h:z){
                    cout << h << " ";
                }
                return 0;
            }
        }
        cout << -1 << "\n";
    }
    else{
        k--;
        int f0=0,f1=16;
        for(int w=0;w<2;w++){
            int y=(1<<k)-1;
            map<int,int> mp;
            for(int u=0;u<(1<<y);u++){
                queue<int> q;
                for(int i=0;i<(1<<k);i++){
                    q.push(i);
                }
                auto z=get(q,u,y,2,1);
                mp[hash(z,f0)]=u;
            }
            for(int u=0;u<(1<<y);u++){
                queue<int> q;
                for(int i=0;i<(1<<k);i++){
                    q.push(i);
                }
                auto z=get(q,u,y,1,1);
                int m=hash(z,f1);
                int b=(h+mod-m)%mod;
                if(mp.find(b)!=mp.end()){
                    auto s=mp[b];
                    vector<int> ans(1<<(k+1));
                    for(int i=f1;i<f1+(1<<k);i++){
                        ans[i]=z[i-f1];
                    }
                    queue<int> q2;
                    for(int i=0;i<(1<<k);i++){
                        q2.push(i);
                    }
                    auto z2=get(q2,s,y,2,1);
                    for(int i=f0;i<f0+(1<<k);i++){
                        ans[i]=z2[i-f0];
                    }
                    for(auto ee:ans){
                        cout << ee << " ";
                    }
                    cout << "\n";
                    return 0;
                }
            }
            swap(f0,f1);
        }
        cout << -1 << "\n";
    }
    return 0;
}