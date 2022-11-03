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
///---program start---///
main()
{
    int now=1;
    int n;
    cin>>n;
    while (now<=n)
    {
        for (int i=1;i<=10;i++)
        {
            if (i*now>n)
            {
                cout<<i*now-n ;
                return(0);
            }
        }
        now*=10;
    }
}