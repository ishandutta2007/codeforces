#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli INF = 1ll<<32;
lli mul(lli a,lli b) {
    if(a>=INF || b>=INF || INF/a<=b || a*b>=INF) return INF;
    else return a*b;
}
lli add(lli a,lli b) {
    if(a>=INF || b>=INF || a>=INF-b) return INF;
    else return a+b;
}

int n,t[100000],arr[100000];
lli f(int &idx) {
    lli ret=0;
    for(;idx<n && t[idx]!=3;idx++) {
        if(t[idx]==1) ret = add(ret,1);
        else if(t[idx]==2) {
            int t=arr[idx++];
            ret = add(ret,mul(t,f(idx)));
        }
    }
    return ret;
}
int main() {
    scanf("%d",&n);

    char str[5];
    for(int i=0;i<n;i++) {
        scanf("%s",str);
        if(str[0]=='a') t[i]=1;
        else if(str[0]=='f') {
            scanf("%d",arr+i);
            t[i]=2;
        } else t[i]=3;
    }
    int i=0;
    lli ans = f(i);
    if(ans>=INF) puts("OVERFLOW!!!");
    else printf("%lld\n",ans);
    return 0;
}