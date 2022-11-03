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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;

bool use[300000];

signed main()
{
    int n,k;
    cin>>n>>k;
    string st;
    cin>>st;
    k=n-k;

    vector<int> vec;

    for (int i=0;i<st.size();i++)
        if (st[i]=='(')
    {
        vec.pb(i);
    } else
    {
        if (k)
        {
            k-=2;
            use[vec.back()]=1;
            use[i]=1;
        }
        vec.pop_back();
    }

    for (int i=0;i<st.size();i++)
        if (!use[i])
        cout<<st[i];
}