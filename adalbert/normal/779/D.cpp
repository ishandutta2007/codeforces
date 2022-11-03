#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define int ll
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
string st2;
int n,use[400000],a[400000];
bool check(string st1)
{
    //cout<<st1<<'\n';
    int now=0;
    for (int i=0;i<st2.size();i++)
    {
        if (now==st1.size()) return(0);
        while (st1[now]!=st2[i])
        {
            now++;
            //cout<<now<<'\n';
            if (now==st1.size()) return(0);
        }
        now++;
    }
    return(1);
}
string st1;
bool check(int d)
{
    for (int i=1;i<=n;i++)
        use[i]=0;
    for (int i=1;i<=d;i++)
        use[a[i]]=1;
    string now="";
    for (int i=1;i<=n;i++)
        if (use[i]==0) now+=st1[i-1];
    return(check(now));
}
signed main()
{
    fast;
    cin>>st1>>st2;
    n=st1.size();
    int l=0;
    int r=st1.size();
    for (int i=1;i<=st1.size();i++)
        cin>>a[i];
    while (r-l>1)
    {
        //cout<<l<<' '<<r<<'\n';
        int d=(l+r)/2;
        if (check(d)) l=d; else r=d;
    }
    while (!check(r) && r!=0) r--;
    cout<<r;
}