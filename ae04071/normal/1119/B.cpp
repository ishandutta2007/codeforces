#include <bits/stdc++.h>
using namespace std;

int n,h,a[1000];

int main() {
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++) scanf("%d",a+i);

    int ans=0;
    for(int k=1;k<=n;k++) {
        long long s=0;
        vector<int> arr;
        for(int i=0;i<k;i++) arr.push_back(a[i]);
        sort(arr.begin(),arr.end());

        for(int i=(k+1)%2;i<k;i+=2) s+=arr[i];
        if(s>h) break;
        ans=max(ans,k);
    }
    printf("%d\n",ans);

    return 0;
}