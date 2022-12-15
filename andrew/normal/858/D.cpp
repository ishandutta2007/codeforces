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
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll maxn=1000000;
struct
{
    ll h, p[10];
} b[1000000];
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
map <string ,ll> mp1;
string s[1000000],s1,s2,ss2;
char cc;
ll bn,c,sc,n,m,i,j,a[1000000],a1,b1,c1,ans,x,k,mx=-1e18;
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
ll addB(string s)
{
    char c;
    ll q = 0, i, n = s.size();

    for (i = 0; i < n; i++)
    {
        c=s[i]-'0';
        if (!b[q].p[c]) b[q].p[c] = bn++;
        q = b[q].p[c];
    }

    return b[q].h;
}
void addBe(string s,ll kek)
{
    char c;
    ll q = 0, i, n = s.size();

    for (i = 0; i < n; i++)
    {
        c=s[i]-'0';
        if (!b[q].p[c]) b[q].p[c] = bn++;
        q = b[q].p[c];
    }

    b[q].h=kek;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    ll i1;
    ss2.clear();
    for(i=0;i<n;i++)cin >> s[i];
    for(i=0;i<n;i++)
    {
        for(i1=0;i1<9;i1++)
        {
            s1=ss2;
            for(j=i1;j<9;j++)
            {
                s1+=s[i][j];
                if(addB(s1)==0)addBe(s1,i+1);else if(addB(s1)!=i+1)addBe(s1,-1);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        mx=1e18;
        for(i1=0;i1<9;i1++)
        {
            s1=ss2;
            for(j=i1;j<9;j++)
            {
                s1+=s[i][j];
                if(addB(s1)==i+1 && s1.size()<mx)
                {
                    mx=s1.size();
                    s2=s1;
                }
            }
        }
        cout << s2 << endl;
    }
    return 0;
}