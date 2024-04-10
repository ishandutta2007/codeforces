#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;
int x[N],y[N],id[N];
bool cmp(int i,int j){
    if(y[i]>=0&&y[j]<0) return true;
    else if(y[i]<0&&y[j]>=0) return false;
    if(y[i]==0&&y[j]==0){
        return x[j]<0;
    }
    return x[i]*y[j]>=x[j]*y[i];
}
bool cmp_frac(long long ap,long long aq,long long bp,long long bq){
    if(ap>=0&&bp<0) return false;
    if(ap<0&&bp>=0) return true;
    if(ap<0&&bp<0) return cmp_frac(-bp,bq,-ap,aq);
    long long as=ap/aq,ar=ap%aq,bs=bp/bq,br=bp%bq;
    if(as<bs) return true;
    else if(as>bs) return false;
    if(br==0) return false;
    else if(ar==0) return true;
    return cmp_frac(bq,br,aq,ar);
}
int main(){
    int n;
    long long ap,aq,tp,tq;
    int now=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]),id[i]=i;
    sort(id,id+n,cmp);
    for(int i=0;i<n;i++){
        int a=id[i],b=id[(i+1)%n];
        tp=x[a]*x[b]+y[a]*y[b];
        if(tp>0) tp=tp*tp;
        else tp=-tp*tp;
        tq=1LL*(x[a]*x[a]+y[a]*y[a])*(x[b]*x[b]+y[b]*y[b]);
        if(now==-1||cmp_frac(ap,aq,tp,tq)){
            ap=tp;
            aq=tq;
            now=i;
        }
    }
    printf("%d %d\n",id[now]+1,id[(now+1)%n]+1);
    return 0;
}