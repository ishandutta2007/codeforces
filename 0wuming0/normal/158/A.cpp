#include"bits/stdc++.h"
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int ans=k;
    a[n+1]=12415;
    for(ans=k;;ans++)
    if(a[k]!=a[ans])break;
    int ans2;
    for(ans2=n;ans2>=1;ans2--)if(a[ans2]!=0)break;//cout<<"ok"<<endl;
    cout<<min(ans-1,ans2)<<endl;
    return 0;
}