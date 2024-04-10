#include <bits/stdc++.h>
using namespace std;

char str[300100];
int n;
int main() {
    scanf("%d%s",&n,str);
    int mx=-1,mi=-1;
    for(int i=0;i<n;i++) {
        if(mx > str[i]-'a') {
            puts("YES");
            printf("%d %d\n",mi+1,i+1);
            return 0;
        }
        if(mx < str[i]-'a') {
            mx=str[i]-'a';
            mi=i;
        }
    }
    puts("NO");
    return 0;
}