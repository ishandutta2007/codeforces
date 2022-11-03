#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1039;

string st[arr];

int bal(string s)
{
    int res=0;

    int mn=0;

    for (auto i:s)
    {
        if (i=='(')
            res++; else
            res--;
        mn=min(mn,res);
    }

    if (mn!=res)
        return(1e18);
    return(res);
}

signed main()
{
    int n,a,b;
    cin>>n>>a>>b;
    if (b==1)
    {
        if (a!=1)
        {
            cout<<"YES\n";
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)

                    if (i==j)
                        cout<<0; else
                    if (i>=a && j>=a)
                        cout<<1; else
                        cout<<0;
                cout<<'\n';
            }
        } else
        {
            if (n<=3 && n>=2)
            {
                cout<<"NO\n";
            } else
            {
                cout<<"YES\n";
                for (int i=1;i<=n;i++)
                {
                    for (int j=1;j<=n;j++)
                        if (abs(i-j)==1)
                            cout<<1; else
                            cout<<0;
                    cout<<'\n';
                }
            }
        }
    } else
    if (a==1)
    {
        swap(a,b);

        if (a!=1)
        {
            cout<<"YES\n";
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)

                    if (i==j)
                        cout<<0; else
                    if (i>=a && j>=a)
                        cout<<0; else
                        cout<<1;
                cout<<'\n';
            }
        }
    } else
    cout<<"NO\n";
}
/*
*/