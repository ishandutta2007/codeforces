#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long i,j,n;


cin>>n;
long mas[10000];
mas[1]=1;
mas[2]=1;
i=1;
j=1;
long per=0;
while ((i<1000)&&(j<1000))
  {
  if (per%2==0)
    i+=j; else
      j+=i;
  mas[i]=1;
  mas[j]=1;
  per++;
  }
string str;
for (i=1; i<=n; i++)
  if (mas[i]==1)
    str+='O'; else
      str+='o';

cout<<str;

    return 0;
}