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
pii a[N],b[N],c[N];
int n,m,res_a[N],res_b[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
    for (int i=1;i<=m;i++) cin>>b[i].fi>>b[i].se,c[i]=mp(b[i].se,b[i].fi);
    int check1=1,check2=1,res=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i]!=b[j] && a[i]!=c[j])
            {
                int tmp;
                if (a[i].fi==b[j].fi || a[i].fi==b[j].se) tmp=a[i].fi;
                else if (a[i].se==b[j].fi || a[i].se==b[j].se) tmp=a[i].se;
                else continue;
                if (res!=0 && res!=tmp) check1=0;
                res=tmp;
                if (res_a[i]!=0 && res_a[i]!=tmp) check2=0;
                res_a[i]=tmp;
                if (res_b[j]!=0 && res_b[j]!=tmp) check2=0;
                res_b[j]=tmp;
            }
    if (check1)
    {
        cout<<res;
        return 0;
    }
    if (check2) cout<<0;
    else cout<<-1;
    return 0;
}