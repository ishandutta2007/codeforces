#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;

#define int ll

int n;

int ask(string st)
{
    cout<<'?'<<' '<<st<<'\n';
    fflush(stdout);
    int a;
    cin>>a;
    return(n-a);
}

string get(int u)
{
    string res="";
    for (int i=1;i<=u;i++)
        res+='1';
    while (res.size()<n) res+='0';
    return(res);
}

signed main()
{
    cin>>n;
    string st=get(0);
    int ask1=ask(st);
    st=get(1);
    int ask2=ask(st);
    bool is0=(ask1>ask2);
//    cout<<is0<<'\n';

    int l=1;
    int r=st.size()-1;
    while (r-l>1)
    {
        int d=(l+r)/2;
        int now=ask(get(d));
        if (is0)
        {
            if (ask1-now==d) l=d; else r=d;
        } else
        {
            if (now-ask1==d) l=d; else r=d;
        }
    }

    int now=ask(get(r));
    if (is0)
    {
        int res;
        if (ask1-now==r) res=r+1; else
            res=l+1;
        cout<<'!'<<' '<<1<<' '<<res;
    } else
    {
        int res;
        if (now-ask1==r) res=r+1; else
            res=l+1;

        cout<<'!'<<' '<<res<<' '<<1;
    }
}