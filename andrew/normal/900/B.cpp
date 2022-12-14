#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
vector <ll> v[MAXN];
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,dp[MAXN];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
     cin >> a1 >> b1 >> c1;
        for(i=1;i<10000000;i++)
        {
            a1%=b1;
            a1*=10;
            if(a1/b1==c1)
            {
                cout << i << endl;
                return 0;
            }
        }
    cout << -1 << endl;

    return 0;
    return 0;
}