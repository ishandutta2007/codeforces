#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

char s[200100];
int dy[]={-1,1,0,0},dx[]={0,0,-1,1};
int get(char ch) {
    if(ch=='W') return 0;
    else if(ch=='S') return 1;
    else if(ch=='A') return 2;
    else return 3;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int n;
        scanf("%s",s);
        n=strlen(s);
        
        int y=0,x=0,ya=0,yb=0,xa=0,xb=0;
        int ay[2]={n,-2},by[2]={n,-2},ax[2]={n,-2},bx[2]={n,-2};
        for(int i=0;i<n;i++) {
            int idx=get(s[i]);
            y+=dy[idx];x+=dx[idx];
            
            ya=min(ya,y);yb=max(yb,y);
            xa=min(xa,x);xb=max(xb,x);
        }
        y=0; x=0;

        if(y==ya) ay[0]=min(ay[0],-1),ay[1]=-1;
        if(y==yb) by[0]=min(by[0],-1),by[1]=-1;
        if(x==xa) ax[0]=min(ax[0],-1),ax[1]=-1;
        if(x==xb) bx[0]=min(bx[0],-1),bx[1]=-1;

        for(int i=0;i<n;i++) {
            int idx=get(s[i]);
            y+=dy[idx];x+=dx[idx];
            
            if(y==ya) ay[0]=min(ay[0],i),ay[1]=i;
            if(y==yb) by[0]=min(by[0],i),by[1]=i;
            if(x==xa) ax[0]=min(ax[0],i),ax[1]=i;
            if(x==xb) bx[0]=min(bx[0],i),bx[1]=i;
        }

        lli ans=1ll*(yb-ya+1)*(xb-xa+1);
        if(yb-ya>1 && (ay[0] > by[1] || ay[1] < by[0])) ans = min(ans,1ll*(yb-ya)*(xb-xa+1));
        if(xb-xa>1 && (ax[0] > bx[1] || ax[1] < bx[0])) ans = min(ans,1ll*(yb-ya+1)*(xb-xa));
        printf("%lld\n",ans);
    }
    return 0;
}