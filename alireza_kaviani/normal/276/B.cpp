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
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int cnt[256];

int main()
{
    fast_io;

    int rem = 0;
    string s;
    cin >> s;

    for(int i = 0 ; i < s.size() ; i++)     cnt[s[i]]++;
    for(int i = 0 ; i < 256 ; i++)     rem += cnt[i] % 2;

    cout << (rem == 0 || rem & 1 ? "First" : "Second") << endl;

    return 0;
}