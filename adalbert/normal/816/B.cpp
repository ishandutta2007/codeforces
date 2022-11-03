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

int cnt[arr];

signed main()
{
    int n,k,q;
    cin>>n>>k>>q;
    for (int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }
    for (int i=1;i<=200100;i++)
        cnt[i]+=cnt[i-1];
    for (int i=1;i<=200100;i++)
        cnt[i]=(cnt[i]>=k);
    for (int i=1;i<=200100;i++)
        cnt[i]+=cnt[i-1];
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<cnt[r]-cnt[l-1]<<'\n';
    }

}