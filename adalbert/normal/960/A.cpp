
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
const int md=1e9+7;
const int arr=7e5;

signed main()
{
    string st;
    cin>>st;
    int a=0,b=0,c=0;
    while (!st.empty() && st.back()=='c')
        c++,st.pop_back();
    while (!st.empty() && st.back()=='b')
        b++,st.pop_back();
    while (!st.empty() && st.back()=='a')
        a++,st.pop_back();

    if (!st.empty() || a==0 || b==0 || (a!=c && b!=c))
        cout<<"NO\n"; else
        cout<<"YES\n";
}