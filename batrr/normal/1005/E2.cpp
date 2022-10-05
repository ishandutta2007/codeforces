#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
int n,m,a[maxn];

ll calc(int m){
    ll cur_sum=0,res=0,cur=0;
    map<ll,ll>sum;
    sum[0]++;
    for(int i=1;i<=n;i++){
        //cur>pre
        if(a[i]<m)
            cur--,cur_sum-=sum[cur];
        else
            cur_sum+=sum[cur],cur++;
        res+=cur_sum;
        //cout<<i<<" "<<cur_sum<<" "<<cur<<" "<<res<<endl;
        sum[cur]++;
    }
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<calc(m)-calc(m+1);
}