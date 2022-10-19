#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        long long s1=a[1],s2=a[2],m1=a[1],m2=a[2],n1=1,n2=1;
        long long ans=1e18;
        ans=min(ans,(n-n1)*m1+(n-n2)*m2+s1+s2);
        for(int i=3;i<=n;i++)
        {
            if(i%2)
            {
                n1++;
                s1+=a[i];
                m1=min(m1,(long long)a[i]);
            }
            else
            {
                n2++;
                s2+=a[i];
                m2=min(m2,(long long)a[i]);
            }
            ans=min(ans,(n-n1)*m1+(n-n2)*m2+s1+s2);
        }
        cout<<ans<<endl;
    }
    return 0;
}