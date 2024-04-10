#include <bits/stdc++.h>
using namespace std;

int main() {
    int test,a,b,c;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",min(max((a+c-b+1)/2, 0),c+1));
    }
    return 0;
}