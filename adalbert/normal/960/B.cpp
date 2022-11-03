
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

signed main()
{
    int n,k1,k2;
    cin>>n>>k1>>k2;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];

    multiset<int> setik;

    for (int i=1;i<=n;i++)
        setik.insert(abs(a[i]-b[i]));

    k1+=k2;
    while (k1--)
    {
        int now=*setik.rbegin();
        setik.erase(setik.find(now));

        now--;
        now=abs(now);
        setik.insert(now);
    }

    int ans=0;

    for (auto i:setik)
        ans+=i*i;

    cout<<ans;
}