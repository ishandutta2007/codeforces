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

bool sub(string s , string t)
{
    bool b = false;
    for(int i = 0 ;i < s.size() - t.size() + 1; i++)
    {
        string temp = s.substr(i , t.size());
        if(temp == t)
        {
            b = true;
        }
    }
    return b;
}

int main()
{
    fast_io;

    vector<pair<int , string>> vec;
    int n;
    cin >> n;

    for(int i = 0 ;i < n ; i++)
    {
        string s;
        cin >> s;
        vec.push_back({s.size() , s});
    }

    Sort(vec);
    for(int i = 0 ;i < n - 1 ; i++)
    {
        if(sub(vec[i + 1].Y , vec[i].Y) == false)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for(int i = 0 ;i < n ; i++)
    {
        cout << vec[i].Y << endl;
    }


    return 0;
}