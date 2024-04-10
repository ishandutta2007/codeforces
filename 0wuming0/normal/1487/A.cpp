#include"bits/stdc++.h"
using namespace std;
int a[300];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
            sort(a,a+n);
        int ans=n;
        for(int i=0;i<n;i++)if(a[i]==a[0])ans--;
        cout<<ans<<endl;
    }
    return 0;
}