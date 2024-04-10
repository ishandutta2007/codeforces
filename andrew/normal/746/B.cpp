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
    cin >> n >> s1;
    if(n%2)
    {
        s2=s1[0];
        for(i=1;i<n;i++)if(i%2)s2=s1[i]+s2;else s2+=s1[i];
        vout(s2);
    }
     s2=s1[0];
    for(i=1;i<n-1;i++)if(i%2==0)s2=s1[i]+s2;else s2+=s1[i];
    s2+=s1[n-1];
    vout(s2);
    return 0;
}