#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c%=3;
        if(c==0) printf("%d\n",a);
        else if(c==1) printf("%d\n",b);
        else printf("%d\n",a^b);
    }
    return 0;
}