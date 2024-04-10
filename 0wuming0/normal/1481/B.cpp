#include"bits/stdc++.h"
using namespace std;
int num[105];
int a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        //for(int i=0;i<105;i++)num[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        int i;
        for(i=1;i<n;i++)
        {
            if(a[i]<a[i+1])break;
        }
        for(int c=1;c<=k;c++)
        {
            if(i>1&&a[i-1]<a[i])i--;
            for(;i<n;i++)
            {
                if(a[i]<a[i+1])break;
            }
            if(i==n)
            {
                cout<<-1<<endl;
                goto ne;
            }
            a[i]++;
        }
        cout<<i<<endl;
        ne:;
    }
    return 0;
}