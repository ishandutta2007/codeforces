#include <iostream>

using namespace std;

long n,x,y,k;

int main()
{
//    cout << "Hello world!" << endl;
cin>>n;
cin>>x>>y;
k=0;
while ((x%10!=7)&&(y%10!=7))
  {
  y-=n;
  if (y<0)
    {
    x--;
    y+=60;
    }
  if (x<0)
    x+=24;
  k++;
  }
cout<<k;
   return 0;
}