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

int a[arr],b[arr];

vector<int> vec;

int solve(int u)
{
    int f=*lower_bound(vec.begin(),vec.end(),u);
    int s=*(--lower_bound(vec.begin(),vec.end(),u));

    return(min(abs(u-f),abs(u-s)));
}

int getp(int u)
{
    return(u/2);
}

signed main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];

    vec.pb(-1e18);
    vec.pb(1e18);
    int s=0;
    for (int i=1;i<=n;i++)
        if (i%2)
            s+=b[i]; else
            s-=b[i];

    vec.pb(s);

    for (int i=n+1;i<=m;i++)
    {
        s-=b[i-n];
        s=-s;
        if (n%2)
            s+=b[i]; else
            s-=b[i];
        vec.pb(s);
    }

    sort(vec.begin(),vec.end());

    int sa=0;
    for (int i=1;i<=n;i++)
        if (i%2)
            sa+=a[i]; else
            sa-=a[i];

    cout<<solve(sa)<<'\n';

    while (q--)
    {
        int l,r,pl;
        cin>>l>>r>>pl;
        int parn=getp(r)-getp(l-1);
        int nparn=(r-l+1-parn);

        sa-=parn*pl;
        sa+=nparn*pl;
        cout<<solve(sa)<<'\n';
    }
}