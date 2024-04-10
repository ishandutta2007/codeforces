#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=4e5+10;
map<ll,ll> cnt;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        cnt[x-i]+=x;
    }
    ll res=0;
    for (auto it=cnt.begin();it!=cnt.end();it++)
    {
        pii tmp=*it;
        res=max(res,tmp.se);
    }
    cout<<res;
    return 0;
}