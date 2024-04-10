#include"bits/stdc++.h"
using namespace std;
int ans[300],sum;
int main()
{
    int k,n;
    cin>>n>>k;
    int a[300];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans[a[i]]=i+1;
    }
    for(int i=0;i<150;i++)
    {
        if(ans[i])sum++;
    }
    if(sum>=k)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<150;i++)
        {
            if(ans[i])
            {
                k--;
                cout<<ans[i];
                if(k==0)
                {
                    putchar(10);
                    return 0;
                }
                else putchar(' ');
            }
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
/*
3 0
1 1 1
*/