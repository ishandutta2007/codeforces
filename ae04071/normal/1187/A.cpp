#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        int t=a+b-n;
        a-=t; b-=t;
        printf("%d\n",max(a,b)+1);
    }
    return 0;
}