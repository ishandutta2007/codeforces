#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=200005;
struct P{
    int x,y,id;
} p[N],st[N];
inline bool cmp(const P a,const P b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool operator >(P a,P b){return a.y<b.y;}
bool operator <(P a,P b){return a.y>b.y;}
priority_queue<P> pq;
int t,n,xx,yy,ans[N],top;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&xx,&yy);
            p[i].x=xx<yy?xx:yy; 
            p[i].y=xx+yy-p[i].x; 
            p[i].id=i+1;
        }
        top=0;
        for(int i=1;i<=n;i++) 
            ans[i]=-1;
        std::sort(p,p+n,cmp);
        st[++top]=p[0];
        for(int i=1;i<n;i++)
            if(p[i].x>p[i-1].x)
                st[++top]=p[i];
        int l=1; P k;
        k.id=0;
        for(int i=1;i<n;i++){
            if(p[i].x>p[i-1].x){
                if(k.id==0||k.y>st[l].y) k=st[l];
                l++;
            }
            if(k.id==0){ 
                ans[p[i].id]=-1;
                continue;
            }
            if(k.y<p[i].y)
                ans[p[i].id]=k.id;
        }
        for(int i=1;i<=n;i++){
            printf("%d",ans[i]);
            putchar(i==n?'\n':' ');
        }
    }
    return 0;
}