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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int arr=6e5;

int a[arr];
signed main()
{
    int n;
    cin>>n;
    map<int,int> len,pred,last;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        len[a[i]]=len[a[i]-1]+1;
        pred[i]=last[a[i]-1];
        last[a[i]]=i;
    }

    int imx=1;

    for (int i=1;i<=n;i++)
        if (len[a[i]]>=len[a[imx]])
            imx=i;

    cout<<len[a[imx]]<<'\n';

    vector<int> vec;

    while (imx!=0)
    {
        vec.pb(imx);
        imx=pred[imx];
    }

    reverse(vec.begin(),vec.end());
    for (auto i:vec)
        cout<<i<<' ';
}
/*
*/