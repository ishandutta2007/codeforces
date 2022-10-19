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
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}

int main()
{
    fast_io;

    int n , n1 , n2;
    cin >> n >> n1 >> n2;
    if(n2 > n1)
    {
        swap(n1 , n2);
    }

    int a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    sort(a , a + n , greater<int>());

    double ans1 = 0 , ans2 = 0 , cnt1 = 0 , cnt2 = 0;
    for(int i = 0 ; i < n2 ; i++)
    {
        ans1 += a[i];
        cnt1 += 1;
    }
    for(int i = n2 ; i < n2 + n1 ; i++)
    {
        ans2 += a[i];
        cnt2 += 1;
    }
    printf("%.10f" , ans1 / cnt1 + ans2 / cnt2);

    return 0;
}