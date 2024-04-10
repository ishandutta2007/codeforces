#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    const int m=2e5+5;
    vector<int> vis(m,0),lpf(m,-1);
    vector<int> p;
    for(int i=2;i<m;i++){
        if(!vis[i]){
            p.push_back(i);
            lpf[i]=i;
        }
        for(auto h:p){
            if(1ll*h*i>=m){
                break;
            }
            vis[h*i]=1;
            lpf[h*i]=lpf[h];
            if(h%i==0){
                break;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<int> pr;
        int z=n;
        while(z>1){
            int k=lpf[z];
            pr.push_back(k);
            while(z%k==0){
                z/=k;
            }
        }
        vector<vector<long long> > f(pr.size(),vector<long long>(n));
        multiset<long long> mp;
        for(int i=0;i<pr.size();i++){
            for(int j=0;j<n/pr[i];j++){
                int nw=j;
                for(int k=0;k<pr[i];k++){
                    f[i][j]+=v[nw];
                    nw+=n/pr[i];
                }
                f[i][j]*=n/pr[i];
                mp.insert(f[i][j]);
            }
        }
        cout << *mp.rbegin() << "\n";
        for(int i=0;i<q;i++){
            int a,c;
            cin >> a >> c;
            a--;
            int u=c-v[a];
            v[a]=c;
            for(int j=0;j<pr.size();j++){
                mp.erase(mp.find(f[j][a%(n/pr[j])]));
                f[j][a%(n/pr[j])]+=1ll*u*n/pr[j];
                mp.insert(f[j][a%(n/pr[j])]);
            }
            cout << *mp.rbegin() << "\n";
        }
    }
    return 0;
}