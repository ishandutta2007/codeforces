#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#define int long long
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=5e5;
int a[arr];
///---program start---///
main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int sum=0;
    for (int i=k;i<=n;i++)
        sum+=a[i]-a[i-k];
    cout<<fixed<<setprecision(9)<<ld(sum)/ld(n-k+1);

}