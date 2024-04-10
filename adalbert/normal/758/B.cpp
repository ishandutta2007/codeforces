#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int a[10000];
signed main()
{
    string st;
    cin>>st;
    int kb=0,kr=0,ky=0,kg=0,r,y,g,b;
    for (int i=0;i<st.size();i++)
        if (st[i]=='R') r=i%4; else
        if (st[i]=='G') g=i%4; else
        if (st[i]=='Y') y=i%4; else
        if (st[i]=='B') b=i%4;
    for (int i=0;i<st.size();i++)
        if (st[i]=='!' && i%4==r) kr++; else
        if (st[i]=='!' && i%4==g) kg++; else
        if (st[i]=='!' && i%4==y) ky++; else
        if (st[i]=='!' && i%4==b) kb++;
    cout<<kr<<' '<<kb<<' '<<ky<<' '<<kg;
}