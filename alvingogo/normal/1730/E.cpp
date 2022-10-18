#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    const int m=1e6+7;
    vector<vector<int> > fac(m);
    for(int i=1;i<m;i++){
        for(int j=i;j<m;j+=i){
            fac[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<int> lb(n,-1),rb(n,n),ls(n,-1),rs(n,n);
        vector<int> s;
        for(int i=0;i<n;i++){
            while(s.size() && v[s.back()]<=v[i]){
                rb[s.back()]=i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for(int i=n-1;i>=0;i--){
            while(s.size() && v[s.back()]<v[i]){
                lb[s.back()]=i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for(int i=0;i<n;i++){
            while(s.size() && v[s.back()]>v[i]){
                rs[s.back()]=i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        for(int i=n-1;i>=0;i--){
            while(s.size() && v[s.back()]>v[i]){
                ls[s.back()]=i;
                s.pop_back();
            }
            s.push_back(i);
        }
        s.clear();
        vector<vector<int> > a(m);
        vector<int> z(m);
        for(int i=0;i<n;i++){
            a[v[i]].push_back(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(auto h:fac[v[i]]){
                if(a[h].empty()){
                    continue;
                }
                int l=-1,r=0;
                while(z[h]<a[h].size() && a[h][z[h]]<=i){
                    z[h]++;
                }
                l=z[h]-1;
                if(l>=0){
                    l=a[h][l];
                    ans+=1ll*max(0,min(i,l)-max(lb[i],ls[l]))*max(0,min(rs[l],rb[i])-i);
                }
                else{
                    l=-97777777;
                }
                r=z[h];
                if(r<a[h].size()){
                    r=a[h][r];
                    ans+=1ll*max(0,i-max({lb[i],ls[r],l}))*max(0,min(rs[r],rb[i])-max(i,r));
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}