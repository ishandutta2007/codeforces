#include <bits/stdc++.h>
using namespace std;

int n,arr[1000001];
int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int s=(i-1)%2*n+((i-1)/2);
        arr[s]=arr[s+n-i]=i;
    }
    for(int i=0;i<n*2;i++) if(!arr[i])arr[i]=n;
    for(int i=0;i<n*2;i++) printf("%d ",arr[i]);
    return 0;
}