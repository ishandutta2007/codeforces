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

int calc(int n)
{
    int mul=1;
    while(n>=10)
    {
        while(n!=0)
        {
            if(n%10!=0)
            {
                mul*=(n%10);
            }
            n/=10;
        }
        n=mul;
        mul=1;
    }
    return n;
}

int t[10];
int main()
{
    vector<int> a[10];
    for(int i=0;i<10;i++)
    {
        a[i]=vector<int> (1000*1000+1);
    }
    for(int i=1;i<=1000*1000;i++)
    {
         int m=calc(i);
         t[m]++;
         for(int j=0;j<10;j++)
         {
             a[j][i]=t[j];
         }
    }
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int l,r,k , ans=0, tem=0;
        cin >> l >> r >> k;

        cout << a[k][r]-a[k][l-1]<< endl;
    }
    return 0;
}