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

int main()
{
    fast_io;

    int see = -1 , st , en = 0;
    string s;
    cin >> s;

    st = s.size() - 1;
    for(en = 0 ; en < s.size() ; en++)
    {
        if(see != -1 && s[en] == 'a')
        {
            break;
        }
        if(s[en] != 'a' && see == -1)
        {
            st = en;
            see = 0;
        }
    }

    for(int i = st ; i < en ; i++)
    {
        s[i] = s[i] - 1;
        (s[i] == 96 ? s[i] = 'z' : s[i] = s[i]);
    }
    cout << s << endl;

    return 0;
}