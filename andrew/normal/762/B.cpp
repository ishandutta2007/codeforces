#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <iomanip>
#include <set>

#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define endl "\n"


using namespace std;
pair<ll,ll> q[1000001];
ll a,b,n,c,r,n1,t,k,j,i;
string s;
int main()
{
    //freopen("digits.in","r",stdin);
    //freopen("digits.out","w",stdout);
    fast_io;
    cin>>a>>b>>c;
    r=a+b+c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>q[i].fi>>s;
        if (s[0]=='U')q[i].se=1;
    }
    sort(q,q+n);
    for(i=0;i<n;i++)
    {
        if(q[i].se==1){if(a>0){n1+=q[i].fi;a--;}else if(c>0){n1+=q[i].fi;c--;}}
        else
        {if(b>0){b--;n1+=q[i].fi;}else if(c>0){c--;n1+=q[i].fi;}}
    }
    cout<<r-a-b-c<<" "<<n1<<endl;
       return 0;
}