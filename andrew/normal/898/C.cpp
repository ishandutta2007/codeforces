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
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
set <string> s,ss1,ss2;
map <string,ll> mp1;
map < string , set <string> > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    while(n--)
    {
        cin >> s1;
        cin >> m;
        for(i=0;i<m;i++)
        {
            cin >> s2;
            mp[s1].insert(s2);
        }
        s.insert(s1);
    }
    set < string > :: iterator it,it1;
    it=s.begin();
    cout << s.size() << endl;
    for(;it!=s.end();++it)
    {
        s1=*it;
        cout << s1 << " ";
        ss1.clear();
        ss2.clear();
        it1=mp[s1].begin();
        for(;it1!=mp[s1].end();++it1)
        {
            s2=*it1;
            while(s2.size()>1)
            {
                s2.erase(0,1);
                ss1.insert(s2);
                mp1[s2]=1;
            }
        }
        for(it1=mp[s1].begin();it1!=mp[s1].end();++it1)if(!mp1[*it1])ss2.insert(*it1);
        cout << ss2.size();
        for(it1=ss2.begin();it1!=ss2.end();++it1)cout << " " << *it1;
        for(it1=ss1.begin();it1!=ss1.end();++it1)mp1[*it1]=0;
        cout << endl;
    }
    return 0;
}