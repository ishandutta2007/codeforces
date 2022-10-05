#include <iostream>

using namespace std;

long long hh,mm,h,d,c,n;

int main()
{
cin>>hh>>mm;
cin>>h>>d>>c>>n;

long ost=20-hh;
ost*=60;
ost-=mm;
ost=max((long )0, ost);

long double ans=0;

long h1=h;
h1--;
h1-=(h1%n);
h1+=n;

long p=h1/n;
p*=c;

ans=p;


h1=h+ost*d;
h1--;
h1-=(h1%n);
h1+=n;

long double c1=c;
c1*=0.8;

long double p1=0;
p1=h1/n;
p1*=c1;

ans=min(p1, ans);


cout.precision(8);
cout<<fixed<<ans;

    return 0;
}