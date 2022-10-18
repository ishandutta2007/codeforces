#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define __int128 long long
using namespace std;

const int mod=998244353;
void add(long long& x,__int128 y){
    x+=y;
    x%=mod;
    x+=mod;
    x%=mod;
}
signed main(){
    AquA;
    long long t;
    cin >> t;
    while(t--){
        long long n,m;
        cin >> n >> m;
        vector<vector<__int128> > e(n);
        vector<__int128> v(n);
        vector<__int128> s;
        vector<__int128> in(n);
        for(__int128 i=0;i<n;i++){
            long long z=1234567890;
            cin >> z;
            v[i]=z;
            //v[i]%=998244353;
            if(v[i]){
                s.push_back(i);
            }
        }
        for(__int128 i=0;i<m;i++){
            long long a,b;
            cin >> a >> b;
            a--;
            b--;
            e[a].push_back(b);
            in[b]++;
        }
        long long ans=0;
        for(__int128 i=0;i<n+5;i++){
            if(s.empty()){
                break;
            }
            for(auto h:s){
                v[h]--;
                for(auto p:e[h]){
                    v[p]++;
                }
            }
            s.clear();
            for(__int128 i=0;i<n;i++){
                if(v[i]>0){
                    s.push_back(i);
                }
            }
            ans++;
        }
        auto in2=in;
        vector<__int128> tp;
        queue<__int128> q;
        for(__int128 i=0;i<n;i++){
            if(in2[i]==0){
                q.push(i);
            }
        }
        for(int i=0;i<n;i++){
            v[i]%=mod;
        }
        while(q.size()){
            auto h=q.front();
            tp.push_back(h);
            q.pop();
            for(auto y:e[h]){
                in2[y]--;
                if(in2[y]==0){
                    q.push(y);
                }
            }
        }
        for(int i=0;i<n;i++){
            int k=tp[i];
            for(auto z:e[k]){
                add(v[z],v[k]);
            }
            if(i==n-1){
                add(ans,v[k]);
            }
        }
        cout << ans%mod << "\n";
    }
    return 0;
}