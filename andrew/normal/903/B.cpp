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
vector <string> sans;
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
    ll h1,a1,c1;
    cin >> h1 >> a1 >> c1;
    ll h2,a2;
    k=h2/a1;
    if(h2/a1)k++;
    cin >> h2 >> a2;
   while(1)
    {
        if(h2<1)break;
        if(h2<=a1)
        {
            sans.p_b("STRIKE");
            break;
        }
        if(h1>a2){sans.p_b("STRIKE");h2-=a1;h1-=a2;}else
            {
                sans.p_b("HEAL");
                h1+=c1;
                h1-=a2;
            }
    }
    cout << sans.size() << endl;;
    for(i=0;i<sans.size();++i)cout << sans[i] << endl;
return 0;
}