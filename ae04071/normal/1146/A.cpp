#include <bits/stdc++.h>
using namespace std;

char str[51];
int main() {
    int n,c=0;
    scanf("%s",str);
    n=strlen(str);
    for(int i=0;i<n;i++) if(str[i]=='a') c++;

    printf("%d\n",min(n,c+c-1));

    return 0;
}