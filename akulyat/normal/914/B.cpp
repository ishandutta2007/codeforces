#include <bits/stdc++.h>

using namespace std;

long n,i,j,g,a;
vector <long> mas;
long kol[200000];

int main()
{
//    cout << "Hello world!" << endl;
cin>>n;
for (i=0; i<n; i++)
  {
  cin>>a;
  mas.push_back(a);
  }
g=0;
sort(mas.begin(), mas.end());
kol[0]=1;
for (i=1; i<n; i++)
  if (mas[i]==mas[i-1])
  {
  kol[i]=kol[i-1]+1;
  } else
  {
  kol[i]=1;
  if (kol[i-1]%2==1)
    g=1;
  }
  if (kol[n-1]%2==1)
    g=1;
if ((g==1)||(n==1))
  cout<<"Conan"; else
    cout<<"Agasa";


    return 0;
}