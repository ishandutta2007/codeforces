#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int q;
    cin >> q;

    while(q--)
    {
        string s;
        cin >> s;
        int x[] = {1 , 2 , 3 , 4 , 6 , 12};
        vector<int> vec;
        for(int i = 0 ; i < 6 ; i++)
        {
            int t = 0;
            for(int j = 0 ; j < x[i] ; j++)
            {
                int fl = 1;
                for(int k = 0 ; k < 12 / x[i] ; k++)    if(s[k * x[i] + j] == 'O')  fl = 0;
                t |= fl;
            }
            if(t)   vec.push_back(x[i]);
        }
        sort(all(vec) , greater<int>());
        cout << vec.size() << ends;
        for(int i = 0 ; i < vec.size() ; i++)   cout << 12 / vec[i] << "x" << vec[i] << ends;
        cout << endl;
    }
    return 0;
}