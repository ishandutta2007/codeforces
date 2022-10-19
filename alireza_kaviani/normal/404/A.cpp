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

int cnt[26];

int main()
{
    fast_io;
    int n;
    cin >> n;

    string s[n];
    for(int i = 0 ;i < n ;i++)
    {
        cin >> s[i];
        for(int j = 0; j < n ;j++)
        {
            cnt[s[i][j] - 'a']++;
        }
    }

    char check = s[0][0];
    bool t = true;
    for(int i = 0 ;i < n ; i++)
    {
        if(s[i][i] != check)
        {
            t = false;
        }
        if(s[i][n - i - 1] != check)
        {
            t = false;
        }
    }

    int l = 0;
    for(int i = 0 ;i < 26 ; i++)
    {
        if(cnt[i] != 0)
        {
            if(i == check - 'a' && cnt[i] != n * 2 - 1)
            {
                t = false;
            }
            else if(i != check - 'a' && cnt[i] != n * n - n * 2 + 1)
            {
                t = false;
            }
            l++;
        }
    }

    if(l == 2 && t)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}