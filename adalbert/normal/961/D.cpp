#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int n;
int x[300000],y[300000];

bool check(int i, int j)
{
    int a=y[i]-y[j];
    int b=x[j]-x[i];
    int c=-(a*x[i]+b*y[i]);


    vector<pair<int,int> > vec;

    for (int i=1;i<=n;i++)
        if (x[i]*a+y[i]*b+c!=0)
        {
            vec.pb({x[i],y[i]});

        }


    if (vec.size()<=2)
        return(1);

    a=vec[0].sec-vec[1].sec;
    b=vec[1].fir-vec[0].fir;
    c=-(a*vec[0].fir+b*vec[0].sec);

    for (int i=2;i<vec.size();i++)
        if (a*vec[i].fir+b*vec[i].sec+c!=0)
        return(0);
    return(1);
}

signed main()
{
    cin>>n;
    if (n<=4)
    {
        cout<<"YES";
        return(0);
    }

    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }


    for (int i=1;i<=3;i++)
        for (int j=i+1;j<=3;j++)
        if (check(i,j))
        {
            cout<<"YES";
            return(0);
        }

    cout<<"NO";
}
/*
6
0 1
0 -1
1 1
1 -1
-1 -1
-1 1
*/