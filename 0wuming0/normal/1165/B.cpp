#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=now)now++;
    }
    cout<<--now<<endl;
    return 0;
}