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
const ll base=31;
const int arr=6e5;
const int md=1e9+9;

int l[arr],r[arr];

bool check(int i, int j)
{
    if (r[i]==r[j])
        return(l[i]>l[j]); else
        return(r[i]<r[j]);
}

signed main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for (int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        vec.pb(i);
    }

    sort(vec.begin(),vec.end(),check);

    int last=0;

    for (auto i:vec)
    {
        if (last!=0 && l[i]<=l[last])
        {
            cout<<last<<' '<<i;
            return(0);
        }
        if (last==0 || l[last]<l[i])
            last=i;
    }

    cout<<-1<<' '<<-1;
}