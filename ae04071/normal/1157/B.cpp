#include <bits/stdc++.h>
using namespace std;

int n,f[10];
char str[200010];

int main() {
    scanf("%d%s",&n,str);
    for(int i=1;i<10;i++) scanf("%d",f+i);
    for(int i=0;i<n;i++) str[i]-='0';
    for(int i=0;i<n;i++) if(str[i] < f[str[i]]) {
        for(int j=i;j<n && str[j]<=f[str[j]];str[j]=f[str[j]],j++);
        break;
    }
    for(int i=0;i<n;i++) str[i]+='0';
    printf("%s\n",str);
    return 0;
}