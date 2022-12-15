#include <bits/stdc++.h>
using namespace std;

char str[10100],ns[10110];
int n,m;

int main() {
    scanf("%s%d",str,&m);
    n=strlen(str);
    for(int i=0;i<m;i++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        l--;r--;
        k%=(r-l+1);
        for(int i=l;i<=r;i++) {
            ns[(i-l+k)%(r-l+1)+l] = str[i];
        }
        for(int i=l;i<=r;i++) str[i] = ns[i];
    }
    printf("%s\n",str);
    return 0;
}