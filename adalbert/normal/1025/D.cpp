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
#pragma GCC optimize ("O3")
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5;

bool leftok[800][800];
bool rightok[800][800];
bool reb[800][800];
int a[800];

signed main()
{
    int n;

    cin>>n;

    for (int i=1;i<=n;i++)
        cin >> a[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (__gcd(a[i],a[j])>1)
        reb[i][j]=1;

    bool ans=0;

    for (int siz=1;siz<=n;siz++)
        for (int i=1; i+siz-1<=n; i++)
    {
        int j=i+siz-1;

        for (int mid=i;mid<=j; mid++)
        {
            if (siz==1 || (leftok[i][mid] || i==mid) && (rightok[mid][j] || j==mid))
            {
                if (j+1<=n && reb[mid][j+1])
                    leftok[i][j+1]=1;
                if (i-1>=1 && reb[mid][i-1])
                    rightok[i-1][j]=1;
                
                if (i==1 && j==n)
                    ans=1;
            }
        }
    }

    if (ans)
    {
        cout<<"Yes";
        return(0);
    }

    cout<<"No";
}