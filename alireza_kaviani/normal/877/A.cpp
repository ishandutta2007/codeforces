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

bool good(string s)
{
    return (s == "Danil" || s == "Olya" || s == "Slava" || s == "Ann" || s == "Nikita");
}

int main()
{
    fast_io;

    int ans = 0;
    string s;
    cin >> s;

    for(int i = 1 ; i <= s.size() ; i++)
    {
        for(int j = 0; j <= s.size() - i ; j++)
        {
            if(good(s.substr(j , i)))
            {
                ans++;
            }
        }
    }
    cout << (ans == 1 ? "YES" : "NO") << endl;

    return 0;
}