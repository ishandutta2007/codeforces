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
    string s[5];
    s[0]="Tetrahedron";
    s[1]="Cube";
    s[2]="Octahedron";
    s[3]="Dodecahedron";
    s[4]="Icosahedron";
    a[0]=4;
    a[1]=6;
    a[2]=8;
    a[3]=12;
    a[4]=20;
    cin >> n;
    while(n--)
    {
        string s1;
        cin >> s1;
        for(i=0;i<5;i++)if(s[i]==s1)ans+=a[i];
    }
    cout << ans << endl;
    return 0;
}