#include <iostream>

#define int long long int
using namespace std;

signed main()
{
    int n=0;
    cin>>n;

    int ans=0;

    int bete=0;
    for(int h=1;h<=1300000;h++){
        bete+=(3*h-1);
        if(n<bete)
            continue;
        if((n-bete)%3==0)
            ans++;
    }

    cout<<ans<<'\n';
    return 0;
}