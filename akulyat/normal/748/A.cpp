#include <bits/stdc++.h>

using namespace std;


long long n,m,k;

int main()
{
cin>>n>>m>>k;
k--;

long long a,b;
char c='L';
if (k&1)
  c='R';

k/=2;

b=k%m;
a=k/m;

cout<<a+1<<' '<<b+1<<' '<<c<<endl;


   return 0;
}