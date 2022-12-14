#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
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
set <pll> s,s1;
const ll shl=1;
const ll MAXN=1123456;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
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
    for(i=0;i<n;i++)cin >> a[i];
    k=1;
    a1=a[0];
    for(i=1;i<n;i++)if(a[i]==a1)k++;else
    {
        s.insert(m_p(-k,i-k));
        s1.insert(m_p(i-k,k));
        k=1;
        a1=a[i];
    }
    s.insert(m_p(-k,i-k));
    s1.insert(m_p(i-k,k));
    set <pll> :: iterator it=s.begin();
    set <pll> :: iterator it1;
    set <pll> :: iterator itl;
    set <pll> :: iterator itr;
    while(!s.empty())
    {
        ans++;
        it=s.begin();
        a1=it->fi;
        b1=it->se;
        s.erase(it);
        it1=s1.find(m_p(b1,-a1));
        itl=it1;
        itr=it1;
        if(it1==s1.begin())itl++;else itl--;
        if(itl==s1.end())break;
        ++itr;
        if(itr==s1.end())
        {
            --itr;
            --itr;
        }
        s1.erase(it1);
        if(a[itl->fi]==a[itr->fi])
        {
            pll x1=*itl,x2=*itr;
            if(x1!=x2)
            {
                s1.erase(*itl);
                s.erase(s.find(m_p(-(x1.se),x1.fi) ) );
                s1.erase(*itr);
                s.erase(s.find(m_p(-(x2.se),x2.fi) ) );
                s.insert(m_p(-(x1.se+x2.se),x1.fi));
                s1.insert(m_p(x1.fi,(x1.se+x2.se)));
            }
        }
    }
    cout << ans << endl;
    return 0;
}