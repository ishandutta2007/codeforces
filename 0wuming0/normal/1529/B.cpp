#include"bits/stdc++.h"
using namespace std;
int a[100005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c;
        int num=0;
        int flag=0;
        int b=1e9;
        nn=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c);
            if(c<=0)
            {
                num++;
                a[nn++]=c;
            }
            else
            {
                flag=1;
                b=min(b,c);
            }
        }
        sort(a,a+nn);
        int d=1e9;
        for(int i=1;i<nn;i++)d=min(a[i]-a[i-1],d);
        if(flag&&d>=b)num++;
        cout<<num<<endl;
    }
    return 0;
}