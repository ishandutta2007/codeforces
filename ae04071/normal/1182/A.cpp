#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    scanf("%d",&n);
    if(n%2!=0) puts("0");
    else printf("%d\n",1<<(n/2));
    return 0;
}