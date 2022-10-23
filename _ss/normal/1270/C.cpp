#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll s1=0,s2=0,x;
        for (int i=1;i<=n;i++) cin>>x,s1+=x,s2^=x;
        ll t=1;
        t<<=(ll)55;
        if (s1&1) t++;
        s2^=t;
        s1+=t;
        s2*=2;
        cout<<"3\n"<<t<<" "<<(s2-s1)/2<<" "<<(s2-s1)/2<<"\n";
    }
    return 0;
}