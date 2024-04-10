// Just say you won't let go
#include <bits/stdc++.h>
#define int long long
#define hash hashhash
#define X first
#define Y second
#define endl "\n"
#define Mp make_pair
using namespace std;
inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline long long lin(){long long x ; scanf("%lld",&x) ; return x ;}
inline string get(){char ch[2000010] ; scanf("%s",ch) ; return ch;}
inline void read(int *a , int n ) { for (int i = 0 ; i < n ; i ++) a[i] = in() ; }
inline int out(int x) {cout << x << endl ; exit(0) ; }
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vii;
const int maxn  = 5e5 + 10;
const int maxm = 1e6 + 10;
const int maxlg = 21;
const int base = 29;
const int mod = 1e9 + 7;
const ll INF = 1e10 + 10;
const int SQ = 317;
int x[maxn],y[maxn],z[maxn],a[maxn],b[maxn],res,prce[maxn];
int32_t main()
{
    int n = in();
    for (int i = 0 ; i < n ; i ++)
        x[i] = in() , y[i] = in() , z[i] = in();
    int m = in();
    for (int i = 0 ; i < m ; i ++) a[i] = in() , b[i] = in() , prce[i] = in();
    for (int i = 0 ; i < n ; i ++)
    {
        int mini = INF;
        x[i] += y[i];
        x[i] *= 2;
        for (int j = 0 ; j < m ; j ++)
        {
            if (a[j] < z[i]) continue;
            int cnt = a[j]/z[i];
            mini = min(mini ,  (x[i] + b[j] * cnt- 1 ) / (b[j] * cnt) * prce[j]);
        }
        res += mini;
    }
    cout << res << endl;
}