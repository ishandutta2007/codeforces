#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define pb push_back
typedef long long ll;
typedef long double ld;
const int arr=300000+10;


signed main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int x,y;
    cin >> x >> y;
    int a=x1-x2;
    int b=y1-y2;
    a=abs(a);
    b=abs(b);
    if (a%x!=0 || b%y!=0)
    {
        cout<<"NO";
        return(0);
    }
    a/=x;
    b/=y;
    //cout<<a<<' '<<b<<'\n';
    if ((a+b)%2!=0)
    {
        cout<<"NO";
        return(0);
    }
    cout<<"YES";

}