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
const ll shl=1;
const ll MAXN=1123456;
vector <ll> tt[1000];
set <ll> s;
map < string , ll > mp;
char cc;
ll ce,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        a[i]=x;
        s.insert(x);
    }

        m=0;
        for(i=0;i<n;i++)
        {
            if(i>1)
            {
                m++;
                b[m]=a[0];
            }
            m++;
            b[m]=a[i];
        }

    for(i=1;i<=m;i++)
    {
        k=b[i];
        for(j=i;j<=m;j++,k=__gcd(k,b[j]))if(s.find(k)==s.end())vout("-1");
    }
    cout << m << endl;
    for(i=1;i<=m;i++)cout << b[i] << " ";
    cout << endl;
    return 0;
}