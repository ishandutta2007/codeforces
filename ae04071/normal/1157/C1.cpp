#include <bits/stdc++.h>
using namespace std;

int n,arr[200000];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int l=0,r=n-1,pr=0;
    vector<int> ans;
    while(l<=r) {
        if(arr[l]==arr[r]) {
            int t=pr,c1=0,c2=0;
            for(int i=l;i<=r && t<arr[i];t=arr[i++],c1++);
            t=pr;
            for(int i=r;i>=l && t<arr[i];t=arr[i--],c2++);
            t=pr;
            if(c1<c2) {
                for(int i=r;i>=l && t<arr[i];t=arr[i--]) ans.push_back(1);
            } else {
                for(int i=l;i<=r && t<arr[i];t=arr[i++]) ans.push_back(0);
            }
            break;
        } else if(pr<arr[l] && pr<arr[r]) {
            if(arr[l]<arr[r]) ans.push_back(0),pr=arr[l++];
            else ans.push_back(1),pr=arr[r--];
        } else if(pr<arr[l]) ans.push_back(0),pr=arr[l++];
        else if(pr<arr[r]) ans.push_back(1),pr=arr[r--];
        else break;
    }
    printf("%d\n",(int)ans.size());
    for(auto &v:ans) printf("%c",v==0 ? 'L' : 'R');

    return 0;
}