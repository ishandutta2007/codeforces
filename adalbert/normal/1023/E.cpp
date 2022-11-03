#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define y eth
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5+100;

bool ask(int x1, int y1, int x2, int y2)
{
    cout<<'?'<<' '<<y1<<' '<<x1<<' '<<y2<<' '<<x2<<'\n';
    fflush(stdout);
    string res;
    cin>>res;
    return(res=="YES");
}

signed main()
{
    int n;
    cin>>n;

    int x=1,y=1;

    string res1="",res2="";

    for (int i=1;i<=n-1;i++)
    {
        if (ask(x+1,y,n,n))
        {
            res1+='R';
            x++;
        } else
        {
            res1+='D';
            y++;
        }
    }

    x=n;
    y=n;

    for (int i=1;i<=n-1;i++)
    {
        if (ask(1,1,x,y-1))
        {
            res2+='D';
            y--;
        } else
        {

            res2+='R';
            x--;
        }
    }

    reverse(res2.begin(),res2.end());
    res1+=res2;

    cout<<'!'<<' '<<res1<<'\n';
    fflush(stdout);
}