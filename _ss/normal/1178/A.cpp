#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
int a[201],n;
int main()
{
    cin>>n;
    int s=0,t=0;
    for (int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    vector<int> ans;
    ans.pb(1);
    t=a[1];
    for (int i=2;i<=n;i++)
        if (a[i]*2<=a[1]) ans.pb(i),t+=a[i];
    if (t>s/2)
    {
        cout<<ans.size()<<endl;
        for (int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    }
    else cout<<0;
    return 0;
}