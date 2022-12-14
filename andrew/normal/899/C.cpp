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
set <ll> s;
map < string , ll > mp;
vector <ll> v1,v2;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k,l,r;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    if(n%4==0)
    {
        l=1;
        r=n;
        for(i=0;i<n/2;i++)
        {
            if(i%2){v1.p_b(l);v1.p_b(r);}else{v2.p_b(l);v2.p_b(r);}
            l++;
            r--;
        }
        cout << 0 << endl;
        cout << v1.size();
        for(i=0;i<v1.size();i++)cout << " "  << v1[i];
        return 0;
    }
    if(n%4==1)
    {
        l=2;
        r=n;
        i=0;
        while(l<r)
        {
            if(i%2){v1.p_b(l);v1.p_b(r);}else{v2.p_b(l);v2.p_b(r);}
            l++;
            r--;
            i++;
        }
        cout << 1 << endl;
        cout << v1.size();
        for(i=0;i<v1.size();i++)cout << " "  << v1[i];
        return 0;
    }
    if(n%4==2)
    {
        l=1;
        r=n;
        for(i=0;i<n/2-1;i++)
        {
            if(i%2){v1.p_b(l);v1.p_b(r);}else{v2.p_b(l);v2.p_b(r);}
            l++;
            r--;
        }
        cout << 1 << endl;
        v1.p_b(n/2);
        cout << v1.size();
        for(i=0;i<v1.size();i++)cout << " "  << v1[i];
        return 0;
    }

    if(n%4==3)
    {
       l=1;
       r=n-1;
       i=0;
       while(l<r)
       {
            if(i%2==0){v1.p_b(l);v1.p_b(r);}
            l++;
            r--;
            i++;
       }

       cout << 0 << endl;
        cout << v1.size();
        for(i=0;i<v1.size();i++)cout << " "  << v1[i];
    }
    return 0;
}