#include<iostream>

using namespace std;

int main()
{
int n;
cin>>n;
if ((n%4!=0)&&(n%4!=3)) cout<<1<<endl;
else cout<<0<<endl;

if (n%4==0) {cout<<n/2<<' '; for (int i = 1; i<=n; i++) if (i*(i-1)%4==0) cout<<i<<' ';}
if (n%4==1) {cout<<(n+1)/2<<' '; for (int i = 1; i<=n; i++) if ((i-2)*(i-1)%4==0) cout<<i<<' ';}
if (n%4==2) {cout<<n/2<<' '<<1<<' '; {for (int i = 3; i<=n; i++) if ((i-2)*(i-3)%4==0) cout<<i<<' ';}}
if (n%4==3) {cout<<(n+1)/2<<' '<<1<<' '<<2<<' '; {for (int i = 4; i<=n; i++) if (i*(i+1)%4==0) cout<<i<<' ';}}
}