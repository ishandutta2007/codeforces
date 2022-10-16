#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

inline double arie(int r){
    return (M_PI*r*r);
}

int v[105];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+n+1);

    double ans=0;

    for(int i=1+(n%2==0);i<=n;i+=2){
        //cout<<i<<' '<<i-1<<endl;
        ans+=(arie(v[i])-arie(v[i-1]));
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
    return 0;
}