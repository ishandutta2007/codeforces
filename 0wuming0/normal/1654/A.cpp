#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        multiset<int>s;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            s.insert(-a);
        }
        int ans=0;
        ans-=*s.begin();
        s.erase(s.begin());
        ans-=*s.begin();
        cout<<ans<<endl;
    }
    return 0;
}