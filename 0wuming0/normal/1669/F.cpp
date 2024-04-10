#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        int ans=0;
        int s1=0,s2=0;
        for(int l=1,r=n;;)
        {
            if(s1==s2)ans=n-(r-l+1);
            if(l>r)break;
            if(s1<s2)
            {
                s1+=a[l];
                l++;
            }
            else
            {
                s2+=a[r];
                r--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}