#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int N=200005;
typedef pair<int,int> pii;
int t,n;
pii p[N],now;
inline int get(pii a,pii b){
    int xa,ya,xb,yb;
    xa=a.first; ya=a.second;
    xb=b.first; yb=b.second;
    if(yb-ya==xb-xa){
        if((xa+ya)&1) return 0;
        return yb-ya;
    }
    if((xb+yb)&1){
        xb-=yb-ya;
        return (xb-xa)/2;
    }
    xb-=yb-ya;
    return (xb-xa+1)/2;
}
int main(){
    scanf("%d",&t);
    long long ans;
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&p[i].first);
        for(int i=0;i<n;i++)
            scanf("%d",&p[i].second);
        sort(p,p+n);
        now={1,1};
        for(int i=0;i<n;i++){
            ans+=get(now,p[i]);
            now=p[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}