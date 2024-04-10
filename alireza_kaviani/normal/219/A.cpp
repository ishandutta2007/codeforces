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

map<char , int> cnt;

int main()
{
    fast_io;

    string s;
    int k;
    cin >> k >> s;

    for(int i = 0; i < s.size(); i++)
    {
        cnt[s[i]] ++;
    }

    for(int i = 0 ;i < s.size() ; i++)
    {
        if(cnt[s[i]] % k != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 0 ;i < k ; i++)
    {
        for(map<char , int>::iterator it = cnt.begin() ; it != cnt.end() ; it++)
        {
            for(int j = 0 ; j < it->Y / k; j++)
            {
                cout << it->X;
            }
        }
    }

    return 0;
}