#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int x[200003],y[200003],d[200003];
int main(){
    int n,h,tmp,tep,ans,sp;
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=1;i<n;i++){
        d[i]=x[i]-y[i-1];
    }
    tmp=y[0]-x[0]; // answer candidate: sum of y-x
    tep=0; // sum of d
    for(sp=1;tep+d[sp]<h && sp < n;sp++){
        tep = tep+d[sp];
        tmp += y[sp]-x[sp];
    }
    ans = tmp;
    for(int i=1;i<n;i++){
        tmp -= y[i-1]-x[i-1];
        tep -= d[i];
        for(;tep+d[sp]<h && sp < n;sp++){
            tep += d[sp];
            tmp += y[sp]-x[sp];
        }
        ans = max(ans,tmp);
    }
    printf("%d",ans+h);
}