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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
char cc;
set <ll> s;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    for(i=0;i<n;i++)
    {
        x=a[i];
        set <ll> :: iterator it=s.begin();
        if(*it==x)continue;
        it=s.end();
        --it;
        if(*it==x)continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}