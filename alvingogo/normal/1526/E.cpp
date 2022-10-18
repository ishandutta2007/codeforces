#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
vector<int> fra;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int inv(int x){
    return x==1?1:mul(mod-mod/x,inv(mod%x));
}
void init(int x){
    fra.resize(x);
    fra[0]=1;
    for(int i=1;i<x;i++){
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
    int n,k;
    cin >> n >> k;
    init(4e5+7);
    vector<int> v(n);
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        x[v[i]]=i;
    }
    x.push_back(-1);
    int cnt=0;
    for(int i=1;i<n;i++){
        int y=v[i],z=v[i-1];
        if(x[y+1]<x[z+1]){
            cnt++;
        }
    }
    cout << conb(n+k-cnt-1,k-cnt-1) << "\n";
    return 0;
}