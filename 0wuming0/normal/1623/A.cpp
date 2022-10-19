#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b,c,d;
        cin>>n>>m>>a>>b>>c>>d;
        int ans1,ans2;
        if(c>=a)ans1=c-a;
        else ans1=n-a+n-c;
        if(d>=b)ans2=d-b;
        else ans2=m-d+m-b;
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}