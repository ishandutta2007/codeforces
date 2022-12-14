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
string s1,s2,s3;
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
    s2="ACGT?";
    k=n/4;
    if(n%4)vout("===");
    cin >> s1;
    for(i=0;i<n;i++)
    {
        int kek=s2.find(s1[i]);
        a[kek]++;
        if(kek<4 && a[kek]>k)vout("===");
    }
    for(i=0;i<n;i++)if(s1[i]=='?')
    {
        for(j=0;j<4;j++)if(a[j]<k)
        {
            s1[i]=s2[j];
            a[j]++;
            break;
        }
    }
    cout << s1 << endl;
    return 0;
}