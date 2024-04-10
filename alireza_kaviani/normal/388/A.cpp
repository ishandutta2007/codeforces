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

const int MAXN = 110;
int cnt[MAXN];

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;
    vector<int> vec(n) , box;
    for(int i = 0 ; i < n ; i++)    cin >> vec[i];
    Sort(vec);

    for(int i = 0 ; i < n ; i++)
    {
        int ind = upper_bound(all(box) , vec[i]) - box.begin() - 1;
        if(ind < 0)
        {
            box.push_back(1);
        }
        else
        {
            box[ind]++;
        }
        Sort(box);
    }
    cout << box.size() << endl;

    return 0;
}