#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

vector<vector<int> > v;
vector<long long> sum;
long long ans=0;
int n,k;
vector<long long> nw;
void dc(int l,int r){
    if(l==r){
        long long cnt=0;
        ans=max(ans,nw[k]);
        for(int i=0;i<min((int)v[l].size(),k);i++){
            cnt+=v[l][i];
            ans=max(ans,nw[k-i-1]+cnt);
        }
        return;
    }
    int m=(l+r)/2;
    auto z=nw;
    for(int i=l;i<=m;i++){
        for(int j=k;j>=0;j--){
            if(j>=v[i].size()){
                nw[j]=max(nw[j],nw[j-v[i].size()]+sum[i]);
            }
        }
    }
    dc(m+1,r);
    nw=z;
    for(int i=m+1;i<=r;i++){
        for(int j=k;j>=0;j--){
            if(j>=v[i].size()){
                nw[j]=max(nw[j],nw[j-v[i].size()]+sum[i]);
            }
        }
    }
    dc(l,m);
    nw=z;
}
int main(){
    AquA;
    cin >> n >> k;
    v.resize(n);
    sum.resize(n);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        for(int j=0;j<t;j++){
            int a;
            cin >> a;
            sum[i]+=a;
            v[i].push_back(a);
        }
    }
    nw.resize(k+1);
    dc(0,n-1);
    cout << ans << "\n";
    return 0;
}