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
typedef long double ld;
const int arr=6e5;

int a[400],can[400];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];


    int res=360;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
    {
        int sum=0;
        for (int l=i;l<=j;l++)
            sum+=a[l];
        res=min(res,abs(360-2*sum));
    }

    cout<<res;
}

/*
1
0.1 0.2 0.3
1.0 0.5 0.3
1.0 0.0 0.2
*/