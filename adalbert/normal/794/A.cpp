#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=500000;
map<int,int> mp;
signed main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    vector<int> vec;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int now;
        cin>>now;
        if (now>b && now<c) ans++;
    }
    cout<<ans;

}