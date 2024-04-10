#include <iostream>

using namespace std;

long long k,d,t,f;
long long off, point, cir, ans;
int main()
{
bool viv=false;
//viv=true;
cin>>k>>d>>t;
t*=2;
f=((k-1)/d+1)*d;
if (viv)
  cout<<"Circle during "<<f<<endl;
off=f-k;
if (viv)
  cout<<"I willn't work minutes: "<<off<<endl;
point=2*k+off;
if (viv)
  cout<<"During "<<f<<" i get "<<point<<endl;
cir=t/point;
if (viv)
  cout<<"It will be "<<cir<<" circles like this"<<endl;
ans=cir*f;
ans*=2;
t%=point;

if (t<=2*k)
  ans+=t;
else
  ans+=(2*k+2*(t-2*k));

cout.precision(10);
cout<<fixed<<(long double)ans/2.0;





    return 0;
}