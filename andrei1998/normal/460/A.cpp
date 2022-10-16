#include <iostream>

using namespace std;

int main()
{
    int n,m;
    int ans=0;

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ans++;

        if(i%m==0)
            n++;
    }

    cout<<ans<<endl;
    return 0;
}