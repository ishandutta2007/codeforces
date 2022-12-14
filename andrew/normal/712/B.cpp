#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef int ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < ll , ll > mp,mp1;
string s,s1;
char cc;
ll p[1000000],c,sc,n,m,i,j,a[1000000],b[1000000],a1,b1,c1,ans,x,k;
void vout(string s)
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
    cin >> s;
    s1="LURD";
    if(s.size()%2)vout("-1");
    for(i=0;i<s.size();i++)
    {
        int kek=s1.find(s[i]);
        a[kek]++;
    }
    if(a[0]<a[2])swap(a[0],a[2]);
    if(a[1]<a[3])swap(a[1],a[3]);
    k=(a[0]-a[2])/2;
    k+=(a[1]-a[3])/2;
    if((a[0]-a[2])%2)k++;
    cout << k << endl;
    return 0;
}