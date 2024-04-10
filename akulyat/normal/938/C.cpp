#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long long t;
cin>>t;
for (long long u=0; u<t; u++)
  {
  long long ked;
  cin>>ked;
  long long got=0;
  for (long long i=1; i<45000; i++)
    if (got==0)
    {
  //  cout<<"try "<<i<<endl;
    long long nul=i*i-ked;
    long long a=0,b=i+1;
    while ((a+1<b)&&(b>1))
      {
      long long m=(a+b)/2;
      long long cur=(i/m)*(i/m);
      if (cur<nul)
        b=m; else
          a=m;
      }
//    if (a==0)
//      cout<<"a=0"<<endl; else
//        cout<<i<<' '<<a<<' '<<((i/a)*(i/a))<<endl;
    if ((a!=0)&&((i/a)*(i/a)==nul))
      {
      cout<<i<<' '<<a<<endl;
      got=1;
      //return 0;
      }
    }
  if (got==0)
    cout<<-1<<endl;
  }

//k=n*n-n/m
  return 0;
}