#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    scanf("%d:%d",&a,&b);
    scanf("%d",&c);
    b+=c;
    a+=b/60, b%=60;
    a%=24;
    printf("%02d:%02d\n",a,b);
    
    return 0;
}