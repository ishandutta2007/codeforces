#include <bits/stdc++.h>
using namespace std;

int n,k;
char str[100100];
int ps[100100];

bool check(int c) {
    for(int i=1;i<=n;i++) if(str[i]=='0') {
        if(ps[min(n,i+c)] - ps[max(1,i-c)-1] >= k+1) return true;
    }
    return false;
}
int main() {
    scanf("%d%d%s",&n,&k,str+1);
    for(int i=1;i<=n;i++) ps[i]=ps[i-1]+(str[i]=='0');

    int lo=0,up=n;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        if(check(md)) up=md;
        else lo=md;
    }
    printf("%d\n",up);
    
    return 0;
}