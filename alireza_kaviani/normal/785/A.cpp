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
#define M                           make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int main()
{
    map<string,int> mp;
    mp["Tetrahedron"]=4;
    mp["Cube"]=6;
    mp["Octahedron"]=8;
    mp["Dodecahedron"]=12;
    mp["Icosahedron"]=20;

    int n;
    cin >> n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        ans+=mp[s];
    }
    cout << ans;

    return 0;
}