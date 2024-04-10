#include <bits/stdc++.h>
using namespace std;
long long v[100000], t[100000];
int n;
vector<long long> vv, tt;
long long ans[100000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&v[i]);
    for(int i=0;i<n;i++) scanf("%lld",&t[i]);
    vv.resize(n); tt.resize(n);
    vv[0] = v[0]; tt[0] = t[0];
    for(int i=1;i<n;i++){
        vv[i] = tt[i-1] + v[i];
        tt[i] = tt[i-1] + t[i];
    }
    sort(vv.begin(),vv.end());
    int cur = 0;
    for(int i=0;i<n;i++){
        while(tt[cur] <= vv[i] && cur < n){
            ans[cur] += (n-i) * t[cur];
            cur++;
        }
        if(cur == n) break;
        ans[cur] += vv[i] - (cur==0?0LL:tt[cur-1]);
    }
    for(int i=0;i<n;i++){
        ans[i] -= (n-1-i) * t[i];
    }
    for(int i=0;i<n;i++){
        printf("%lld ",ans[i]);
    }
}