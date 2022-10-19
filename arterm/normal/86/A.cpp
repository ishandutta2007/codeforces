#include <iostream>

#define long long long

using namespace std;

long l,r,p[20],ans=0;


int main()
{
    p[0]=1;
    for (long i=1; i<=18; ++i)
    p[i]=10*p[i-1];
    cin>>l>>r;
    for (long i=1; i<=18 && p[i-1]<=r; ++i){
        if (l<=p[i]/2-1 && p[i]/2-1<=r)
        ans=max(ans,((p[i]/2)*(p[i]/2-1)));
        if (l<=p[i]/2 && p[i]/2<=r)
        ans=max(ans,((p[i]/2)*(p[i]/2-1)));
        if (p[i]>r)
        ans=max(ans,((p[i]-1-r)*r));
        if (p[i-1]<l)
        ans=max(ans,((p[i]-1-l)*l));
    }
    cout<<ans;
    return 0;
}