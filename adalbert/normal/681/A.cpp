#include <bits/stdc++.h>;
#define fin freopen("next.in","r",stdin)
#define fout freopen("next.out","w",stdout)
using namespace std;
long long n,p,k,r;
string st;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>st>>p>>k;
        if ((p>=2400)&&(k>p)) r=12;
    }
    if (r==12) cout<<"YES"; else cout<<"NO";
}