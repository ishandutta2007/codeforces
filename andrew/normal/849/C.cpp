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
string ans;
char cc;
ll a[maxn],b[maxn],c,a1,b1,c1,n,r,m,x,i,j,sc,k;
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
    cin >> n;
    if(n==0)vout("a");
    cc='a';
    cc--;
    for(i=0;i<26;i++)
    {
        if(n==0)break;
        r=1;
        cc++;
        ans+=cc;
        //cout << n << endl;
        while(n-r>=0)
        {
            n-=r;
            r++;
            ans+=cc;
        }
    }
cout << ans << endl;

return 0;
}