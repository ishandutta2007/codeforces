#include <bits/stdc++.h>
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;


signed main()
{
    int n,a,b;
    cin>>n>>a>>b;

    for (int c1=0;c1*a<=n;c1++)
        if ((n-c1*a)%b==0)
    {

        vector<int> vec;
        for (int i=1;i<=n;i++)
            vec.pb(i);
        for (int i=1;i<=c1;i++)
        {
            int fir=(i-1)*a;
            int sec=fir+a-1;
            for (int i=fir+1;i<=sec;i++)
                swap(vec[i],vec[i-1]);
        }

        for (int i=1;i<=(n-c1*a)/b;i++)
        {

            int fir=c1*a+(i-1)*b;
            int sec=fir+b-1;
            for (int i=fir+1;i<=sec;i++)
                swap(vec[i],vec[i-1]);
        }


        for (auto i:vec)
            cout<<i<<' ';

        return(0);
    }

    cout<<-1;
}
/*
*/