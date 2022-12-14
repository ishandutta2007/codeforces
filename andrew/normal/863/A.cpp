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
string s,s1;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
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
    cin >> s;
    s1=s;
    reverse(s1.begin(),s1.end());
    for(i=0;i<100;i++)
    {
        if(s==s1)vout("YES");
        s="0"+s;
        s1=s1+"0";
    }
    vout("NO");
return 0;
}