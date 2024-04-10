#include"bits/stdc++.h"
using namespace std;
int a[105],b[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)scanf("%d",b+i);
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n;i++)if(a[i]==b[i]||a[i]+1==b[i])continue;
        else
        {
            cout<<"no"<<endl;goto ed;
        }
        cout<<"yes"<<endl;
        ed:;
    }
    return 0;
}