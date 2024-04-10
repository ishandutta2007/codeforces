#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<pii,int>               piii;
typedef pair<pll,ll>                plll;
typedef pair<pdd,double>            pddd;
typedef pair<pld,ld>                pldd;
typedef vector<int>                 vi;
typedef vector<ll>                  vll;
typedef vector<double>              vd;
typedef vector<ld>                  vld;
typedef vector<pii>                 vpii;
typedef vector<pll>                 vpll;
typedef vector<pdd>                 vpdd;
typedef vector<pld>                 vpld;
typedef vector<piii>                vpiii;
typedef vector<plll>                vplll;
typedef vector<pddd>                vpddd;
typedef vector<pldd>                vpldd;

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

bool is_ok(int a,int b)
{
    return abs(a-b)!=1;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vi ans;
        string s;
        cin >> s;

        int t=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='W' && t!=0)
            {
                ans.pb(t);
                t=0;
            }
            else if(s[i]!='W')
            {
                t++;
            }
        }
        if(t!=0)
        {
            ans.pb(t);
        }

        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i] << ends;
        }
        cout << endl;
    }

    return 0;
}