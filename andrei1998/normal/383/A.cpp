#include <iostream>

using namespace std;

int main()
{
    long long int ans=0;

    int n=0;
    cin>>n;

    int nr=0;
    int x;
    while(n--){
        cin>>x;

        if(!x)
            ans+=nr;
        else
            nr++;
    }

    cout<<ans<<'\n';
    return 0;
}