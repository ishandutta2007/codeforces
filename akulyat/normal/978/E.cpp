#include <iostream>

using namespace std;

long long n,w,i;

int main()
{
cin>>n>>w;
long long mini=0, maxi=0;
long long cur=0;
for (i=0; i<n;  i++)
  {
  long long a;
  cin>>a;
  cur+=a;
  mini=min(mini, cur);
  maxi=max(maxi, cur);
  }
maxi-=mini;
maxi--;
w-=maxi;
w=max(w, (long long)0);
cout<<w;


    return 0;
}