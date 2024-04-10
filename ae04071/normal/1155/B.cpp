#include <bits/stdc++.h>
using namespace std;

int n;
char str[300100];
int main() {
    scanf("%d%s",&n,str);
    
    int r=(n-11)/2;
    for(int i=0,j=0;i<n && j<=r;i++) {
        if(str[i]=='8') j++;
        if(j==r+1) {
            if(i-r>r) puts("NO");
            else puts("YES");
            return 0;
        } else if(i==n-1) {
            puts("NO");
            return 0;
        }
    }
    
    return 0;
}