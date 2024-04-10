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
char cc;
vector <pll> v;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
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
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)b[i]=a[i];
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)if(b[i]==a[j])
        {
            if(i!=j)
            {
                swap(a[i],a[j]);
                v.p_b(m_p(i,j));
            }
            break;
        }
    }
    cout << v.size() << endl;
    for(i=0;i<v.size();i++)cout << v[i].fi << " " << v[i].se << endl;
    return 0;
}