#include <bits/stdc++.h>
using namespace std;

int n,m;
int main() {
    scanf("%d%d",&n,&m);
    
    int mn=2*n,mm=3*m;
    for(int i=6;i<=min(mn,mm);i+=6) {
        if(mn+2 <= mm+3) mn+=2;
        else mm+=3;
    }
    printf("%d\n",max(mn,mm));
    
    
    return 0;
}