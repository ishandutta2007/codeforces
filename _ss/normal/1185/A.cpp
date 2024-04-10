#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
ll a[4],d;
int main()
{
    cin>>a[1]>>a[2]>>a[3]>>d;
    sort(a+1,a+4);
    int t1=a[2]-a[1],t2=a[3]-a[2],ans=0;
    if (t1<d) ans+=d-t1;
    if (t2<d) ans+=d-t2;
    cout<<ans;
    return 0;
}