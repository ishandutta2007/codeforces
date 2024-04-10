#include <bits/stdc++.h>
using namespace std;

int n,a,b,T,ps[500101];
char str[500100];

int cal(int i,int j) {
    return i+(n-j+1)+(ps[i]+ps[n]-ps[j-1])*b+(2*(i-1)+(n-j+1))*a;
}
int get() {
    int ret=0,i=1,j=n+1;
    while(j>i && cal(i,j)<=T) j--;
    if(j==n+1) return 0;
    if(i==j) return n;
    j++;

    ret = i+(n-j+1);
    for(;i<=n;i++) {
        while(j<=n && cal(i,j)>T) j++;
        if(cal(i,j)>T) break;
        ret = max(ret, i + (n-j+1));
    }
    return ret;
}
int main() {
    scanf("%d%d%d%d%s",&n,&a,&b,&T,str+1);
    for(int i=1;i<=n;i++) ps[i] = ps[i-1]+(str[i]=='w');
    
    int ans = get();
    reverse(str+2,str+n+1);
    for(int i=1;i<=n;i++) ps[i] = ps[i-1]+(str[i]=='w');
    printf("%d\n",max(ans,get()));
    
    return 0;
}