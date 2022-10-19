#include <bits/stdc++.h>
using namespace std;
const int N=55;

int n;
char a[N];

int main()
{
    cin>>a;
    n=strlen(a);
    int ans=0;
    for(int r=0;r<n;++r)
    {
        for(int l=0;l<=r;++l)
        {
            string s;
            for(int i=l;i<=r;++i)
                s+=a[i];
            string ss=s;
            reverse(s.begin(),s.end());
            if(s!=ss)
                ans=max(ans,(r-l+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}