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

const int MAXN = 1050;
map<int , bool> mark;
map<int , int > cnt;

int main()
{
    fast_io;

    int n;
    cin >> n;

    mark[1] = 1;
    vector<int> ans;
    for(int i = 2 ;i <= n ; i++)
    {
        if(mark[i])
        {
            continue;
        }
        for(int j = i ;j < MAXN ; j += i)
        {
            mark[j] = 1;
            cnt[j]++;
        }
    }

    for(int i = 1 ; i <= n; i++)
    {
        if(cnt[i] == 1)
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(int i : ans)
    {
        cout << i << ends;
    }

    return 0;
}