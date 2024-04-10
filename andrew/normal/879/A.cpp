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
const ll maxn=1000000;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char cc;
ll c,sc,n,m,i,j,a[1000000],b[1000000],a1,b1,c1,ans,x,k;
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
    cin >> n;
    cin >> a1 >> b1;
    c1=a1+1;
    for(i=1;i<n;i++)
    {
        cin >> a1 >> b1;
        if(a1>=c1)c1=a1+1;else
        {
            k=c1-a1;
            sc=k/b1;
            if(k%b1!=0)sc++;
            //if(sc==0)sc++;
            c1=a1+b1*sc+1;
        }
    }
    cout << c1-1 << endl;
    return 0;
}