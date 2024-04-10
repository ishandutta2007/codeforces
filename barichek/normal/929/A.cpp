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
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=1e6;

int x[10000];

signed main()
{
    //files("genome");
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>x[i];

    int last=1;
    int ans=0;
    while (last!=n)
    {
        int start=last;
        while (last+1<=n && x[last+1]-x[start]<=k)
            last++;
        //cout<<last<<'\n';
        if (last==start)
        {
            cout<<-1;
            return(0);
        }
        ans++;
    }

    cout<<ans;
}
/*
6
4
2 4 1 2
7 2 5 1
*/