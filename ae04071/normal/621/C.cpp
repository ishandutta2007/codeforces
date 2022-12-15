#include <bits/stdc++.h>
using namespace std;

int n,m,l[100001],r[100001];

int get(int l,int r) {
    return r/m - (l+m-1)/m+1;
}
double rev(int l,int r) {
    int v=r-l+1;
    return 1.0*(v-get(l,r)) / v;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d%d",l+i,r+i);

    double ans=0;
    for(int i=0,j=n-1,k=1;i<n; i++,j=(j+1)%n,k=(k+1)%n) {
        double a=rev(l[i],r[i]),b=rev(l[j],r[j]),c=rev(l[k],r[k]);
        a=1.0-a; b=1.0-b; c=1.0-c;
        ans += (b*(1-c) + c*(1-b))*(1-a)*1000;
        ans += (1- (1-a)*(1-b)*(1-c) - ((b*(1-c)+c*(1-b))*(1-a)))*2000;
    }
    printf("%.10lf\n",ans);
    
    return 0;
}