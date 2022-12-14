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
ll c[MAXN],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
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
    cin >> n >> m;
    if(n==1 && m==0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    if(m==0 or n*9<m)vout("-1 -1");
    a[0]=1;
    b[0]=1;
    for(i=1;i<m;i++)
    {
        for(j=0;j<n;j++)if(a[j]<9){a[j]++;break;}
    }
    for(i=1;i<m;i++)
    {
        for(j=n-1;j>-1;j--)if(b[j]<9){b[j]++;break;}
    }
    for(i=0;i<n;i++)cout << b[i];
    cout << " ";
    for(i=0;i<n;i++)cout << a[i];cout << endl;
    return 0;
}