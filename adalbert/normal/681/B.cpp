#include <bits/stdc++.h>;
#define fin freopen("next.in","r",stdin)
#define fout freopen("next.out","w",stdout)
using namespace std;
long long n,p,k,r,o;
string st;
int main()
{
    cin>>n;
    for (int a=0;a<=900;a++)
    for (int b=0;b<=9000;b++)
    {
        o=n-1234567*a-123456*b;
        if ((o%1234==0)&&(o>=0)) r=12;
    }
    if (r==12) cout<<"YES"; else cout<<"NO";
}