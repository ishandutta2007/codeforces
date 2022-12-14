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
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> x;
        ll fl=0;
        for(i=0;i<1000;i++)if(3*i<=x && (x-3*i)%7==0){fl=1;break;}
        if(fl==1)cout << "YES";else cout << "NO";
        cout << endl;
    }


return 0;
}