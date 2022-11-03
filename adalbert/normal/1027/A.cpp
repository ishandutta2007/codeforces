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
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
const int arr=2e5;

bool check (char a, char b)
{
    int aa=a-'a';
    int bb=b-'a';


    if ((aa-1+26)%26==(bb-1+26)%26 && aa!=0 && bb!=0)
        return(1);
    if ((aa-1+26)%26==(bb+1+26)%26 && aa!=0 && bb!=25)
        return(1);
    if ((aa+1+26)%26==(bb+1+26)%26 && aa!=25 && bb!=25)
        return(1);
    if ((aa+1+26)%26==(bb-1+26)%26 && aa!=25 && bb!=0)
        return(1);

    return(0);
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i=0;i<s.size();i++)
    {
        if (!check(s[i],s[s.size()-i-1]))
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
}