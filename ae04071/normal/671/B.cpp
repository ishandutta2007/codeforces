#include <bits/stdc++.h>
using namespace std;

int n,k,arr[500000];

int f() {
    int lo=1,up=1e9+1;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        long long cnt=0;
        for(int i=0;i<n;i++) if(arr[i] < md) cnt += md-arr[i];
        if(cnt > k) up=md;
        else lo=md;
    }
    return lo;
}
int g() {
    int lo=0,up=1e9;
    while(up-lo>1) {
        int md=(lo+up)>>1;
        long long cnt=0;
        for(int i=0;i<n;i++) if(arr[i] > md) cnt += arr[i]-md;
        if(cnt > k) lo=md;
        else up=md;
    }
    return up;
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    
    if(n==1) {
        printf("%d\n",arr[0]);
        return 0;
    }
    
    int m1=f(), m2=g();
    if(m1>=m2) {
        long long sum=0;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum%n==0) printf("%d\n",0);
        else printf("%d\n",1);
    } else {
        printf("%d\n",m2-m1);
    }
    
    return 0;
}