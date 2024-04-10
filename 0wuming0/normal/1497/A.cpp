#include"bits/stdc++.h"
using namespace std;
int a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)for(int j=i;j<n;j++)
        {
            if(a[j]==i)
            {
                swap(a[i],a[j]);
                break;
            }
        }
        for(int i=0;i<n;i++)printf("%d%c",a[i]," \n"[i==n-1]);
    }
    return 0;
}