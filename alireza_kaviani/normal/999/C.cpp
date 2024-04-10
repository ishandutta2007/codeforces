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

string Remove(string s , char k , int &c)
{
    string ans = "";
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == k && c >= 1)
        {
            c--;
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}

int main()
{
    fast_io;

    int n , c;
    string s;
    cin >> n >> c >> s;

    for(int i = 0 ; i < 26 ; i++)
    {
        s = Remove(s , 97 + i , c);
        if(c == 0)  break;
    }
    cout << s << endl;

    return 0;
}