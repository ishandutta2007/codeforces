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
vector <ll> v1,v2;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    a[1]=31;a[2]=28;a[3]=31;
    a[4]=30;a[5]=31;
    a[6]=30;
    a[7]=31;
    a[8]=31;
    a[9]=30;
    a[10]=31;
    a[11]=30;
    a[12]=31;
    for(i=1;i<=32;i++)
    {
        if(i%4==0)a[2]++;
        for(j=1;j<=12;j++)v1.p_b(a[j]);
        if(i%4==0)a[2]--;
    }
    cin >> n;
    for(i=1;i<=n;i++)cin >> b[i];
    for(i=0;i<v1.size();i++)
    {
        k=i;
        ll fl=0;
        for(j=1;j<=n;j++)
        {
            if(v1[k]!=b[j])
            {
                fl=1;
                break;
            }
            k++;
            if(k==v1.size())k=0;
        }
        if(fl==0)vout("YES");
    }
    vout("NO");
    return 0;
}