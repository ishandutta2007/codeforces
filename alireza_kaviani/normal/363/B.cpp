#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '

int main()
{
    int n , k;
    cin >> n >> k;

    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i<k)
        {
            sum+=a[i];
        }
    }

    int ans=1e9;
    int ans2=0;
    for(int i=0;i<=n-k;i++)
    {
        if(ans>sum)
        {
            ans=sum;
            ans2=i+1;
        }
        sum=sum-a[i]+a[i+k];
    }
    cout << ans2 << endl;

    return 0;
}