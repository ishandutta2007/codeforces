#include <bits/stdc++.h>
using namespace std;

int val[100001];
int n;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        val[v] = val[v-1]+1;
    }
    printf("%d\n",n-*max_element(val+1,val+n+1));
    return 0;
}