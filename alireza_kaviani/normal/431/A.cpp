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
    map<char,int> mp;
    char d[]={'0','1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<4;i++)
    {
        int a;
        cin >> a;
        mp[d[i+1]]=a;
    }

    int ans=0;
    string s;
    cin >> s;

    for(int i=0;i<s.size();i++)
    {
        ans+=mp[s[i]];
    }
    cout << ans << endl;

    return 0;
}