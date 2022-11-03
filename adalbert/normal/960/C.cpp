
 #include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int a[arr],b[arr];
int x,d;

vector<int> vec;

void solve(int start, int n)
{
    if (n==0)
        return;
    int now=1;
    while ((1ll<<(now+1))-1<=n)
        now++;

    for (int i=0;i<now;i++)
        vec.pb(start);
    solve(start+d+10,n-(1ll<<now)+1);
}

signed main()
{
    cin>>x>>d;

    solve(1,x);

    cout<<vec.size()<<'\n';
    for (auto i:vec)
        cout<<i<<' ';
}