#include<cstdio>
#include<algorithm>
using namespace std;
int t,w,W,H,h,x1,x2,y1,y2,ww,hh;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&W,&H);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d%d",&w,&h);
        ww=x2-x1;
        hh=y2-y1;
        if(ww+w>W&&hh+h>H){
            puts("-1");
            continue;
        }
        int ans=1e9;
        if(ww+w<=W){
            ans=min(ans,max(0,w-(x1)));
            ans=min(ans,max(0,w-(W-x2)));
        }
        if(hh+h<=H){
            ans=min(ans,max(0,h-(y1)));
            ans=min(ans,max(0,h-(H-y2)));
        }
        printf("%d\n",ans);
    }
    return 0;
}