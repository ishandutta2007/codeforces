#include<cstdio>
#include<map>
#include<utility>
#include<algorithm>
#define N 200100
using namespace std;
long long f1[N]={0},f2[N]={0},v[N],tt=0;
int t[N],md[N],h[N],all[N],p[N];
void upd(int x,int n){
    long long m=1LL*n*all[x];
    while(x<N){
        f1[x]+=n;
        f2[x]+=m;
        x+=x&-x;
    }
    tt+=n;
}
long long sum(long long *a,int x){
    long long ans=0;
    while(x){
        ans+=a[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    int n,q,i,j,l,r,m,sz;
    map<int,int> id;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) scanf("%d",&h[i]),all[i]=h[i];
    for(j=0;j<q;j++){
        scanf("%d",&t[j]);
        if(t[j]==1){
            scanf("%d%d",&p[j],&md[j]);
            all[i++]=md[j];
        }
        else{
            scanf("%I64d",&v[j]);
        }
    }
    sort(all+1,all+i);
    sz=unique(all+1,all+i)-all;
    for(i=1;i<sz;i++){
        id.insert(make_pair(all[i],i));
    }
    for(i=1;i<=n;i++){
        upd(id[h[i]],1);
    }
    for(j=0;j<q;j++){
        if(t[j]==1){
            upd(id[h[p[j]]],-1);
            upd(id[md[j]],1);
            h[p[j]]=md[j];
        }
        else{
            l=1;
            r=sz;
            while(r-l>1){
                int m=(l+r)/2;
                if(sum(f2,m)+v[j]<=sum(f1,m)*all[m]) r=m;
                else l=m;
            }
            //printf("v=%lld,l=%d,height=%d,sum1=%lld,sum2=%lld\n",v[j],l,all[l],sum(f1,l),sum(f2,l));
            printf("%.5f\n",all[l]+1.0*(v[j]+sum(f2,l)-sum(f1,l)*all[l])/sum(f1,l));
        }
    }
    return 0;
}