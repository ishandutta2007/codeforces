#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
struct ban
{
    double x,y,r;
};
const int N=100005;

double r,d;
int n;
ban a[N];
double her(ban q)
{
    return sqrt((q.x)*(q.x)+(q.y)*(q.y)+0.0);
}
int main()
{
    //input
    cin>>r>>d;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i].x>>a[i].y>>a[i].r;
    //
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(her(a[i])-a[i].r>=r-d && her(a[i])+a[i].r<=r)
            ++ans;
    }
    //
    cout<<ans<<endl;
    return 0;
}