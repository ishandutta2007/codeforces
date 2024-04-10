#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll

typedef long long ll;
typedef double ld;
const int arr=6e5;

int pluss[arr],a[arr];

signed main()
{
    int n,d;
    cin>>n>>d;

    vector<pair<int,int> > vec;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=n;i>=1;i--)
        pluss[i]=max(pluss[i+1]+a[i],(ll)0);


    int res=0;
    int now=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=0)
        {
            now+=a[i];
            if (now>d)
            {
                cout<<-1;
                return(0);
            }
        }
        else
        {
            if (now<0)
            {
                now=d-pluss[i];
                res++;
            }

            if (now<0)
            {
                cout<<-1;
                return(0);
            }
        }
    }

    cout<<res;
}
/*

*/