#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000], Mn, Mx, r;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(i==1)Mn=Mx=w[i];
        Mn=min(Mn,w[i]);
        Mx=max(Mx,w[i]);
    }
    for(i=1;i<=n;i++){
        if(Mn < w[i] && w[i]<Mx)r++;
    }
    printf("%d\n",r);
}