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

int cnt[1000];

signed main()
{
    int n;
    string st;

    cin>>n>>st;

    for (auto i:st)
        cnt[i]++;

    for (int i='a';i<='z';i++)
        if (cnt[i]>=2 || cnt[i]==n)
    {
        cout<<"Yes";
        return(0);
    }

    cout << "No";
}