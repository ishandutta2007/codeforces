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

    int n , sum = 0 , ans = 0;
    string k;
    cin >> n >> k;

    vector<int> num;
    for(int i = 0 ;i < k.size() ; i++)
    {
        num.push_back(9 - (k[i] - '0'));
        sum += 9 - num[i];
    }

    Sort(num);

    while(sum < n)
    {
        sum += num.back();
        num.pop_back();
        ans++;
    }
    cout << ans << endl;

    return 0;
}