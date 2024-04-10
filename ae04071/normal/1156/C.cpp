#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
using namespace std;

int n,z,arr[200000];
int main() {
    scanf("%d%d",&n,&z);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);

    int lo=0,up=n/2+1;
    while(up-lo>1) {
        int md=(lo+up)>>1,f=1;
        for(int i=0;i<md;i++) {
            if(arr[n-md+i]-arr[i]<z) {
                f=0;
                break;
            }
        }
        if(f) lo=md;
        else up=md;
    }
    printf("%d\n",lo);
    return 0;
}