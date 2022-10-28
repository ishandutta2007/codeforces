#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n;
int a[N];

int32_t main()
{ 
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    int ans1=0, ans2=0;
    int tim=10;
    for(int i=1;i<=n;i++)
    {
        tim+=a[i];
        if(tim>720)
            break;
        ans1++;
        ans2+=max(0, tim-360);
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}