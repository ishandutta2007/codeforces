#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define clear(x) memset(x,0,sizeof(x))
typedef long long ll;
const int N=410,M=200005;
int n,k,cur[N],T,st[N],top;
bool use[N];
ll ans;
struct node{
    int l,r;
    inline bool operator <(const node &x){
        if(l==x.l) return r<x.r;
        return l<x.l;
    }
} p[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        clear(use);
        for(int i=0;i<k;i++){
            scanf("%d%d",&p[i].l,&p[i].r); 
            if(p[i].l>p[i].r) swap(p[i].l,p[i].r);
            use[p[i].l]=1; use[p[i].r]=1;
        }
        top=0;
        for(int i=1;i<=2*n;i++)
            if(!use[i]) st[top++]=i;
        for(int i=0;i<top/2;i++)
            p[k++]={st[i],st[i+top/2]};
        sort(p,p+k);
        ans=0;
        int l=0,r=1;
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                // if(i==j) continue;
                if(p[i].l<p[j].l&&p[i].r>p[j].l&&p[i].r<p[j].r) ans++;
                if(p[j].l<p[i].l&&p[j].r>p[i].l&&p[j].r<p[i].r) ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}