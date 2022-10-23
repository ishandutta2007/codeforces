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

int lim;
int ask(int x,int k,vi vt)
{
    cout<<"? "<<1<<" "<<k<<"\n";
    cout<<x<<"\n";
    for (int y : vt) cout<<y<<" ";
    cout<<endl;
    int res;
    cin>>res;
    lim--;
    return res;
}

void ans(int k,vi vt)
{
    cout<<"! "<<k<<" ";
    for (int x : vt) cout<<x<<" ";
    cout<<endl;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        lim=n;
        int tt=n;
        while (tt>1) tt>>=1,lim++;
        int d=n,sv=1;
        for (int i=1;i<n;i++)
        {
            vi vt;
            for (int j=i+1;j<=n;j++) vt.eb(j);
            int val=ask(i,vt.size(),vt);
            if (val!=0)
            {
                d=i;
                sv=val;
                break;
            }
        }
        vi unde;
        for (int i=d+1;i<n;i++)
        {
            vi vt;
            vt.eb(i);
            int val=ask(d,1,vt);
            if (val==0) unde.eb(i);
            else sv-=val;
        }
        if (sv==0) unde.eb(n);
        int l=1,r=d-1,check=0;
        while (l<r)
        {
            int mid=(l+r)/2,val;
            if (mid-l+1>=r-mid)
            {
                vi vt;
                for (int j=l;j<=mid;j++) vt.eb(j);
                val=ask(d,vt.size(),vt);
                if (val!=0) check=1;
            }
            else
            {
                vi vt;
                for (int j=mid+1;j<=r;j++) vt.eb(j);
                int tmp=ask(d,vt.size(),vt);
                if (tmp!=0) check=1;
                if (tmp!=0) val=0;
                else val=1;
            }
            if (val!=0)
            {
                for (int j=mid+1;j<=r;j++) unde.eb(j);
                r=mid;
            }
            else
            {
                for (int j=l;j<=mid;j++) unde.eb(j);
                l=mid+1;
            }
        }
        if (l==r && !check)
        {
            vi vt;
            vt.eb(l);
            int val=ask(d,1,vt);
            if (val==0) unde.eb(l);
        }
        ans(unde.size(),unde);
    }
    return 0;
}