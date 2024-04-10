#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const long double INF=1000000,EPS=0.0000000000001;
const int N=1002;

int n;
long double rad;
long double a[N];
long double ans[N];
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin>>n>>rad;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
    {
        ans[i]=rad;
        for(int j=0;j<i;++j)
        {
            ans[i]=max(ans[i],sqrt((2.0*rad)*(2.0*rad)-(a[i]-a[j])*(a[i]-a[j]))+ans[j]);
        }
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}