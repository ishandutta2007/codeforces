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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n , ans = 0;
    string s , t;
    cin >> n >> s >> t;

    for(int i = 0 ; i < n / 2 ; i++)
    {
        int flag = 0;
        set<int> st;
        char a[] ={s[i] , s[n - i - 1] , t[i] , t[n - i - 1]};
        for(int i = 0 ; i < 4 ; i++)    st.insert(a[i]);
        if((a[0] == a[2] && a[1] == a[3]) || (a[0] == a[3] && a[1] == a[2]))    ans += 0;
        else if(a[0] == a[1] && a[2] == a[3])    ans += 0;
        else if(st.size() == 4 || (st.size() == 3 && a[0] == a[1])) ans += 2;
        else    ans += 1;
    }
    cout << ans + (n % 2 == 1 && s[n / 2] != t[n / 2] ? 1 : 0) << endl;

    return 0;
}