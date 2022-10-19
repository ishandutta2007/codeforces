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
int main()
{
    bool a[10000];
    int t1=1,t2=1;
    for(int i=0;i<15;i++)
    {
        a[t2]=1;

        int t=t1;
        t1=t2;
        t2=t+t2;
    }

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            cout << "O";
        }
        else
        {
            cout << "o";
        }
    }
    return 0;
}