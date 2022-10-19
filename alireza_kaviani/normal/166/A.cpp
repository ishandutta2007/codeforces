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

bool cmp(pii a , pii b)
{
    if(a.X == b.X)
    {
        return a.Y < b.Y;
    }
    return a.X > b.X;
}

int count(vector<pii> vec , pii key)
{
    int ans = 0;
    for(int i = 0 ; i < vec.size() ; i++)   ans += (vec[i] == key);
    return ans;
}

int main()
{
    fast_io;

    int n , k;
    cin >> n >> k;

    vector<pii> vec;
    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        vec.push_back({x , y});
    }
    sort(all(vec) , cmp);   k--;

    cout << count(vec , vec[k]) << endl;

    return 0;
}