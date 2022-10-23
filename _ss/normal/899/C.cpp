#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int t=0;
    vector<int> ans;
    for (int i=n;i;i--)
    {
        if (t<=0) t+=i,ans.pb(i);
        else t-=i;
    }
    cout<<t<<endl<<ans.size();
    for (int i=0;i<ans.size();i++) cout<<" "<<ans[i];
    return 0;
}