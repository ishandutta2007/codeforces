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

    string s;
    cin >> s;

    map<char , int> col;

    vector<int> sec(4 , 0);
    for(int i = 0 ;i < s.size() ; i++)
    {
        if(s[i] == '!')
        {
            sec[i % 4]++;
        }
        else
        {
            col[s[i]] = i % 4;
        }
    }

    cout << sec[col['R']] << ends << sec[col['B']] << ends << sec[col['Y']] << ends << sec[col['G']]  << endl;



    return 0;
}