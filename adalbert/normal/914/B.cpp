#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;
int md=998244353;

int cnt[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }

    for (int i=1;i<arr;i++)
        if (cnt[i]%2)
    {
        cout<<"Conan"<<'\n';
        return(0);
    }

    cout<<"Agasa";
}