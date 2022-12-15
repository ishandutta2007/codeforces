#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    for(int i=16;i>=0;i--) if(n>>i&1) printf("%d ",i+1);
    return 0;
}