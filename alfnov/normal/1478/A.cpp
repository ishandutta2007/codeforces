#include<bits/stdc++.h>
using namespace std;
int a[100005],h[100005];
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
for(int i=1;i<=n;i++)scanf("%d",&a[i]),h[a[i]]++;
int ans=0;
for(int i=1;i<=n;i++)ans=max(ans,h[a[i]]),h[a[i]]--;
cout<<ans<<endl;
}
return 0;
}