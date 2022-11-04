#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fir first
#define sec second
#define pb push_back
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define y1 drfijortjubo
using namespace std;
typedef double ld;
typedef long long ll;
const int arr=2e5+10;


signed main()
{
    int n;
    cin>>n;
    string st;
    getline(cin,st);
    getline(cin,st);
    st+=' ';
    int res=0;
    int mx=0;
    for (int i=0;i<st.size();i++)
        if (st[i]>='A' && st[i]<='Z') res++; else
        if (st[i]==' ')
        {
            mx=max(mx,res);
            res=0;
        }
    cout<<mx;

}