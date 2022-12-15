#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,arr[200000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);

    vector<int> ans;
    for(int i=0,j=0;i<n;i=j) {
        for(j=i;j<n && (j==i || arr[j]<=arr[j-1]+1) && (j<=i+1 || arr[j]<=arr[j-2]+1);j++);
        if(j-i>ans.size()) {
            ans.clear();
            for(j=i;j<n && (j==i || arr[j]<=arr[j-1]+1) && (j<=i+1 || arr[j]<=arr[j-2]+1);j++) ans.push_back(arr[j]);
        }
        if(j>i+2) j--;
    }
    printf("%lu\n",ans.size());
    for(int i=ans.size()-1;i>=0;i-=2) printf("%d ",ans[i]);
    for(int i=ans.size()%2;i<ans.size();i+=2) printf("%d ",ans[i]);
    
    return 0;
}