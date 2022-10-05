#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,kolu=0,ans=0;
char last;
cin>>n;
for(long i=0; i<n; i++)
  {
  char s;
  cin>>s;
//  cout<<s;
  if ((s==last)&&(kolu*2==i))
    ans++;
  if (s=='U')
    kolu++;
  last=s;
  }

cout<<ans;



    return 0;
}