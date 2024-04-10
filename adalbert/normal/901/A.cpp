#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".txt","r",stdin); freopen (name".txt","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=500000;

vector<int> inlev[arr];

int a[arr],pred[arr],pred1[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n+1;i++)
    {
        cin>>a[i];
    }

    int last=1;
    inlev[1].pb(1);
    a[1]--;
    bool ch=1;

    for (int i=2;i<=n+1;i++)
    {
        int now=0;
        while (a[i]--)
        {
            if (now!=0)
                ch=0;
            pred[++last]=inlev[i-1][now];
            pred1[last]=inlev[i-1][0];
            inlev[i].pb(last);
            now++;
            now%=inlev[i-1].size();
        }
    }

    if (ch)
    {
        cout<<"perfect"<<'\n';
        return(0);
    } else
    {
        cout<<"ambiguous"<<'\n';
        for (int i=1;i<=last;i++)
            cout<<pred[i]<<' ';
        cout<<'\n';
        for (int i=1;i<=last;i++)
            cout<<pred1[i]<<' ';

    }
}