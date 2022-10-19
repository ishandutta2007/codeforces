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
    map<string , string> mp;

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string s,s1;
        cin >> s >> s1;
        mp[s1]=s;
    }

    for(int i=0;i<m;i++)
    {
        string s,s1;
        cin >> s >> s1;

        cout << s << ' ' << s1 << " #";
        s1.pop_back();
        cout << mp[s1] << endl;
    }
    return 0;
}