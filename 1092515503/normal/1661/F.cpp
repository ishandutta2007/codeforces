#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// bool mb;
int n,a[200100];
ll sum,m,res;
pair<ll,ll>p[20000100];
int P;
ll calc(int a,int b){
    int c=a/b;
    return 1ll*c*c*(b*(c+1)-a)+1ll*(c+1)*(c+1)*(a-b*c);
}
// bool me;
int main(){
    // printf("%d %d %lf\n",&me,&mb,(&me-&mb)/1024.0/1024.0);
    //    freopen("F.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i;i--)a[i]-=a[i-1];
    sort(a+1,a+n+1);
    for(int u=1,v;u<=n;u=v){
        for(v=u;v<=n&&a[u]==a[v];v++);
        int A=a[u];
        sum+=calc(A,1)*(v-u);
        for(int l=1,r;l<A;l=r+1){
            r=A/(A/l);
            if(r!=l)p[++P]=make_pair(calc(A,l)-calc(A,l+1),1ll*(r-l)*(v-u));
            if(r!=A)p[++P]=make_pair(calc(A,r)-calc(A,r+1),v-u);
        }
    }
    // printf("%d\n",v.size());
    sort(p+1,p+P+1);
    scanf("%lld",&m);
    for(int i=P;i&&sum>m;i--){
        auto x=p[i];
     //   printf("%lld %lld\n",x.first,x.second);
        ll num=(sum-m-1)/x.first+1;
        if(num<=x.second){res+=num;break;}
        sum-=x.first*x.second,res+=x.second;
    }
    printf("%lld\n",res);
    return 0;
}