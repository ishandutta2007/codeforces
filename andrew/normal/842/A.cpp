#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
double a1;
ll a[maxn],b[maxn],c,b1,c1,n,m,i,j,sc,ans;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    double l,r,y,x,k;
    cin >> l >> r >> x >> y >> k;
    for(i=l;i<=r;i++)
    {
        a1=i/k;
        b1=a1;
        //cout << fixed << setprecision(10) << b1 << endl;
        if(b1*k!=i)continue;
        if(i-(a1*k)<=1e-9 && (i-(a1*k)>=0)&& x<=a1 && a1<=y)vout("YES");
    }
    cout << "NO" << endl;
return 0;
}