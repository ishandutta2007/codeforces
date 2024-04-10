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

int cnt[105][105];

int main()
{
    int n , k;
    cin >> n >> k;

    string s[n];
    for(int i = 0; i < n ; i++)
    {
        cin >> s[i];
    }

    for(int i = 0 ;i <= n - k ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            bool ok = true;
            for(int l = i ; l < i + k ; l++)
            {
                if(s[l][j] == '#')
                {
                    ok = false;
                }
            }

            if(ok)
            {
                for(int l = i ; l < i + k ; l++)
                {
                    cnt[l][j]++;
                }
            }
        }
    }

    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0; j <= n - k; j++)
        {
            bool ok = true;
            for(int l = j ; l < j + k ; l++)
            {
                if(s[i][l] == '#')
                {
                    ok = false;
                }
            }

            if(ok)
            {
                for(int l = j ; l < j + k ; l++)
                {
                    cnt[i][l]++;
                }
            }
        }
    }

    int mi = 0 , mj = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(k == 1)
            {
                cnt[i][j] /= 2;
            }
            if(cnt[mi][mj] < cnt[i][j])
            {
                mi = i;
                mj = j;
            }
        }
    }
    cout << mi + 1 << ends << mj + 1 << endl;
    return 0;
}