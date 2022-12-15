#include <bits/stdc++.h>
using namespace std;

int n,arr[200000],k;
bool check(int l,int &p) {
    for(int i=0,j=0;j<n;j++) {
        while(i<=j && arr[j]-arr[i]>2*l) i++;
        if(j-i>=k) {
            p=arr[i]+l;
            return true;
        }
    }
    return false;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",arr+i);

        int lo=-1,up=1e9,ret;
        while(up-lo>1) {
            int md=(lo+up)>>1;
            if(check(md,ret)) up=md;
            else lo=md;
        }
        check(up,ret);
        printf("%d\n",ret);
    }
    return 0;
}