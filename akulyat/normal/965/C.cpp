#include <iostream>

using namespace std;

long long n,k,m,d,i;

int main()
{
cin>>n>>k>>m>>d;


long long ans=0;
for (i=1; i<=d; i++)
  {
  long long a=0, b=m+1;
  while (a+1!=b)
    {
    long long mi=(a+b)/2;
    long long n1=n;
    n1/=mi;
    if (n1%k!=0)
      {
      n1-=(n1%k);
      n1+=k;
      }
    n1/=k;
//    cout<<"If i use "<<mi<<" sweats "<<" 'A' get it "<<n1<<" times"<<endl;
    if (n1>=i)
      a=mi;
    else
      b=mi;
    }
//  cout<<"Razdam po "<<a<<endl;
  ans=max(ans, a*i);
  }

cout<<ans;

    return 0;
}