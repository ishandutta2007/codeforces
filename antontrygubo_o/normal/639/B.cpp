#include <bits/stdc++.h>
using namespace std;


int main()
{
int n, d, h;
cin>>n>>d>>h;
if (2*h<d) {cout<<-1; return 0;}
if ((n!=2)&&(d==1)) {cout<<-1; return 0;}
for (int i = 2; i<=h+1; i++) cout<<i-1<<' '<<i<<endl;
if (d>h)
{
    cout<<1<<' '<<h+2<<endl;
    for (int i = h+3; i<=d+1; i++) cout<<i-1<<' '<<i<<endl;
}
if (d==h)
for (int i = d+2; i<=n; i++) cout<<2<<' '<<i<<endl;
else
for (int i = d+2; i<=n; i++) cout<<1<<' '<<i<<endl;
}