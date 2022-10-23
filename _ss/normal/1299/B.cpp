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
pii a[N],b[N];
int n;

int gcd(int x,int y)
{
    while (y)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return abs(x);
}

pii co(pii p1,pii p2)
{
    int t1=p2.fi-p1.fi,t2=p2.se-p1.se;
    //int tmp=gcd(t1,t2);
    //t1/=tmp;
    //t2/=tmp;
    //cout<<t1<<" "<<t2<<"\n";
    return mp(t1,t2);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se,b[i].fi=-a[i].fi,b[i].se=-a[i].se;
    a[n+1]=a[1];
    b[n+1]=b[1];
    set<pii> st;
    for (int i=1;i<=n;i++)
    {
        st.insert(co(a[i],a[i+1]));
        //cout<<st.size()<<"\n";
        st.insert(co(b[i],b[i+1]));
        //cout<<st.size()<<"\n";
    }
    if ((int)st.size()==n) cout<<"YES";
    else cout<<"NO";
    return 0;
}