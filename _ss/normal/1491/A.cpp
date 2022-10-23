#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;
int a[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,cnt1=0;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt1+=a[i];
    }
    for (int i=1,t,k;i<=q;i++)
    {
        cin>>t>>k;
        if (t==1)
        {
            cnt1-=a[k];
            a[k]^=1;
            cnt1+=a[k];
        }
        else if (k<=cnt1) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}