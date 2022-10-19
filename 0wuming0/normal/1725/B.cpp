#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int s=0;
    if(a[0]>m)cout<<n<<endl;
    else
    {
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>m)continue;
            int k=m/a[i];
            s+=k;
            if(s>i)
            {
                cout<<n-i-1<<endl;
                return 0;
            }
        }
    }
    return 0;
}
/*
6 1
1 1 1 1 1 1
*/