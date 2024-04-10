#include <iostream>

using namespace std;

int v[100005];

int main()
{
    int n=1,d=1;
    cin>>n>>d;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    long long int ans=0;
    int j=1;

    for(int i=1;i<=n;i++) {
        while(j+1<=n && v[j+1]-v[i]<=d)
            j++;

        ans+=((j-i-1ll)*(j-i)/2);
    }

    cout<<ans<<'\n';
    return 0;
}