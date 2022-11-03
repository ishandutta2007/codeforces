#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

///-----------------------------------------------------------------------///
int main()
{
    int n;
    cin>>n;
    int ans=n/2;
    cout<<ans<<'\n';
    for (int i=1;i<ans;i++)
        cout<<2<<' ';
    cout<<2+n%2;
}