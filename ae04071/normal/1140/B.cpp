#include <bits/stdc++.h>
using namespace std;

char str[101];
int n;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%s",&n,str);
        
        int mx=n;
        for(int i=0;i<n;i++) if(str[i]=='>') {
            mx=min(mx,i);
            break;
        }
        for(int i=n-1;i>=0;i--) if(str[i]=='<') {
            mx=min(mx,n-i-1);
            break;
        }
        printf("%d\n",mx);
    }
    return 0;
}