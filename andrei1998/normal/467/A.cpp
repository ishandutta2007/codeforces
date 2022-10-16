#include <iostream>

using namespace std;

int p[105];
int q[105];

int main()
{
    int n=0;
    cin>>n;

    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        cin>>q[i];

        q[i]-=p[i];
        ans+=(q[i]>=2);
    }

    cout<<ans<<endl;
    return 0;
}