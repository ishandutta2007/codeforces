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
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int max_n=1e5;

int main()
{
    int n,m;
    cin >> n >> m;

    int a[n];
    vector<int> vec(n+1,0);
    vector<bool> see(max_n,false);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    vec[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        if(!see[a[i]])
        {
            see[a[i]]=true;
            vec[i]=vec[i+1]+1;
        }
        else
        {
            vec[i]=vec[i+1];
        }
    }

    for(int i=0;i<m;i++)
    {
        int l;
        cin >> l;
        l--;
        cout << vec[l] << endl;
    }

    return 0;
}