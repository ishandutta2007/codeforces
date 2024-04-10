#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x[4],y[4];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
    if(n==1 || (n==2 && (x[0]==x[1] || y[0]==y[1]))) puts("-1");
    else {
        int wl=1000, wr=-1000, hu=-1000, hd=1000;
        for(int i=0;i<n;i++) wl=min(wl,x[i]), wr=max(wr,x[i]);
        for(int i=0;i<n;i++) hu=max(hu,y[i]), hd=min(hd,y[i]);
        printf("%d\n",(wr-wl)*(hu-hd));
    }
    return 0;
}