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
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    cin >> a1;
    cin >> b1;
    for(i=0;i<=n;i++)
    {
        c1=a1*i;
        if(c1>n)break;
        if((n-c1)%b1==0)
        {
            cout << "YES" << endl << i << " " << (n-c1)/b1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}