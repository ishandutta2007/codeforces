#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
typedef long long ll;
typedef long double ld;
const int arr=300000+10;
#define int ll
map<int,int> cnt;

int a[arr];

signed main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a+1,a+1+n);
    int ans=1;
    for (int i=1;i<=3;i++)
    {
        ans*=cnt[a[i]];
        cnt[a[i]]--;
    }
    if (a[1]==a[2] && a[2]==a[3])
        cout<<ans/6; else
    if (a[1]!=a[2] && a[2]!=a[3])
        cout<<ans; else
        cout<<ans/2;
}