#include <bits/stdc++.h>
using namespace std;

int n,d,h;
int main() {
    scanf("%d%d%d",&n,&d,&h);
    if(d>2*h || (h==1 && d==1 && n!=2)) {
        puts("-1");
        return 0;
    }

    for(int i=1;i<=h;i++) printf("%d %d\n",i,i+1);
    for(int i=0;i<d-h;i++) {
        if(i==0) printf("%d %d\n",1,h+2);
        else printf("%d %d\n",h+i+1,h+i+2);
    }
    if(d==h) {
        for(int i=d+2;i<=n;i++) printf("2 %d\n",i);
    }else for(int i=d+2;i<=n;i++) printf("1 %d\n",i);
    
    return 0;
}