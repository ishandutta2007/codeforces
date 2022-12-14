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
set <ll> s;
map <ll,ll> mp;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k,f,l,kl,sc1;
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

    cin >> a1 >> b1 >> f >> k;
    if(b1<f)vout("-1");
    //l++;
    kl=b1;
    kl-=f;
    a[0]=a1;
    sc1=0;
    for(i=2;i<=3*k;i++)a[i]=a[i-2];
    while(1)
    {
       // cout << kl << " " << sc1 << " " << a[l] << endl;
        if(sc1==k-1)
        {
            if(abs(f-a[l])>kl)
            {
                ans++;
                if(abs(f-a[l])>b1)vout("-1");
            }
            break;
        }
        if(2*abs(f-a[l])>kl)
        {
            if(2*abs(f-a[l])>b1)vout("-1");
            kl=b1;
            ans++;
        }
            kl-=2*abs(f-a[l]);
        //kl-=2*abs(f-a[l]);
        l++;
        sc1++;
    }
cout << ans << endl;
return 0;
}