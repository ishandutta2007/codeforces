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

int count_s(string s , char t1 , char t2)
{
    int cnt = 0;
    for(int i = 0; i < s.size() - 1 ; i++)
    {
        if(s[i] == t1 && s[i + 1 ] == t2)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    fast_io;

    string s;
    int maxn = 0 , ans = 0;
    cin >> s >> s;

    for(int i = 0; i < s.size() - 1 ; i++)
    {
        int t = count_s(s , s[i] , s[i + 1]);
        if(t > maxn)
        {
            maxn = t;
            ans = i;
        }
    }

    cout << s[ans] << s[ans + 1] << endl;

    return 0;
}