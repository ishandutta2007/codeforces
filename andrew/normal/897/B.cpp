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
vector <ll> tt[1000];
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> k;
    for(i=1;i<=100001;i++)
    {
        a1=i;
        x=i;
        while(x)
        {
            a1*=10;
            a1+=x%10;
            x/=10;
        }
        s.insert(a1);
        if(s.size()>n)s.erase((--s.end()));

    }
    set <ll> :: iterator it=s.begin();
    for(;it!=s.end();++it){ans+=*it;ans%=k;}
    cout << ans%k << endl;
    return 0;
}