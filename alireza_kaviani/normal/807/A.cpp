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
inline int input(){int n; cin >> n ; return n;}

bool sorted(vector<pii> vec)
{
    int n = vec.size();
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(vec[i].X < vec[i + 1].X)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    fast_io;

    int n;
    cin >> n;

    vector<pii> vec;
    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        vec.push_back({x , y});
        if(x != y)
        {
            cout << "rated" << endl;
            return 0;
        }
    }

    if(sorted(vec))
    {
        cout << "maybe" << endl;
        return 0;
    }
    cout << "unrated" << endl;

    return 0;
}