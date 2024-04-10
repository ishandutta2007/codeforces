#include <bits/stdc++.h>
using namespace std;

int t, n,x;
int a[1000000], b[1000000];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i = 0;i<n;i++) cin>>a[i];
        for(int i = 0;i<n;i++) cin>>b[i];
        reverse(a,a+n);
        bool bl = 1;
        for(int i=0;i<n;i++)if(a[i]+b[i]>x) bl=0;
        if(bl)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}