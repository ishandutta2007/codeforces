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

bool v(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' | c=='y');
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    string ans=string(1,s[0]);
    for(int i=1;i<n;i++)
    {
        if(!(v(s[i]) && v(s[i-1])))
        {
            ans+=s[i];
        }
    }

    cout << ans << endl;

    return 0;
}