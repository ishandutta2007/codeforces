#include <iostream>
using namespace std;

int n,a,b;
int main()
{
    cin>>n>>a>>b;
    int ans=0;
    for(int i=1;i<n;++i)
    {
        int x=min(a/i,b/(n-i));
        ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}