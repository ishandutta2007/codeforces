#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long t,n,u,i,j,m,k,maxi;
long kr[10000];

cin>>t;
for (u=0; u<t; u++)
  {
  cin>>n>>k;
  for (i=0; i<k; i++)
    cin>>kr[i];
  long maxi=max(kr[0], n+1-kr[k-1]);
  for (i=0; i<k-1; i++)
    if ((kr[i+1]-kr[i])/2+1>maxi)
      maxi=(kr[i+1]-kr[i])/2+1;
  cout<<maxi<<endl;
  }



return 0;
}