#include"bits/stdc++.h"
using namespace std;
int sum[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        sum[a]++;
        sum[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(sum[i]==2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}