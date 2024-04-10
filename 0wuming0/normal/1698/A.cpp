#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        cout<<a[1]<<endl;
    }
    return 0;
}