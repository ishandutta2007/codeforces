#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
#define si size
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
pii a[maxn];
int n;

ll s(pii obj1,pii obj2,pii obj3)
{
    return ((obj2.fi-obj1.fi)*(obj2.se+obj1.se)+(obj3.fi-obj2.fi)*(obj3.se+obj2.se)+(obj1.fi-obj3.fi)*(obj1.se+obj3.se));
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se,a[i].se-=a[i].fi*a[i].fi;
    sort(a+1,a+n+1);
    vector<pii> st;
    for (int i=1;i<=n;i++)
    {
        while (st.si()>1 && s(st[st.si()-2],st.back(),a[i])<=0) st.pop_back();
        st.pb(a[i]);
    }
    int d=0;
    for (int i=0;i<st.size()-1;i++)
        if (st[i].fi!=st[i+1].fi) d++;
    cout<<d;
    return 0;
}