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
#define ends

int sum(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}

int main()
{
    int k;
    cin >> k;

    int i=0 , j=k;
    while(j!=0)
    {
        int t=sum(i);

        if(t<=10 && t!=0)
        {
            j--;
        }
        if(j==0)
        {
            cout << i << 10-t << endl;
        }
        i++;
    }

    return 0;
}