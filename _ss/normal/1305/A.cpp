#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
int n,a[N],b[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        for (int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<"\n";
    }
    return 0;
}