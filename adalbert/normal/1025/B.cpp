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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5;


int n;
int a[arr],b[arr];

vector<int> fact(int u)
{
    vector<int> res;

    for (int i=2;i*i<=u;i++)
    {
        int cnt=0;
        while (u%i==0)
        {
            u/=i;
            cnt++;
        }
        if (cnt!=0)
            res.pb(i);
    }

    if (u!=1)
        res.pb(u);
    return(res);
}

bool check(int u)
{
    for (int i=1;i<=n;i++)
        if (a[i]%u!=0 && b[i]%u!=0)
        return(0);
    return(1);
}

signed main()
{
    cin >> n;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }

    vector<int> vec=fact(a[1]);

    for (auto i:vec)
        if (check(i))
    {
        cout<<i;
        return(0);
    }

    vec=fact(b[1]);

    for (auto i:vec)
        if (check(i))
    {
        cout<<i;
        return(0);
    }

    cout<<-1;
}