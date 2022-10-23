#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e6+10,mod=1e9+7,inf=1e18;

int mark[N],n,b[N],ps[N],a[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sl=0;
    cin>>n;
    for (int i=1,len;i<=n;i++)
    {
        cin>>len;
        for (int i=1;i<=len;i++) cin>>b[i];
        int flag=0;
        for (int i=1;i<len;i++)
            if (b[i]<b[i+1]) flag=1;
        if (flag) mark[i]=1,sl++;
        else ps[b[len]]++,a[i]=b[1];
    }
    ll res=0;
    for (int i=1;i<=1e6;i++) ps[i]+=ps[i-1];
    for (int i=1;i<=n;i++)
        if (mark[i]) res+=(ll)n;
        else
        {
            res+=(ll)sl;
            if (a[i]>0) res+=(ll)ps[a[i]-1];
        }
    cout<<res;
    return 0;
}