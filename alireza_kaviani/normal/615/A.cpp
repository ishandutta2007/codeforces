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

bool and_g(vector<bool> a)
{
    bool ans=true;
    for(int i=0;i<a.size();i++)
    {
        ans&=a[i];
    }
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<bool> b(m,false);
    for(int i=0;i<n;i++)
    {
        int s;
        cin >> s;
        for(int j=0;j<s;j++)
        {
            int x;
            cin >> x;
            x--;
            b[x]=true;
        }
    }
    if(and_g(b))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}