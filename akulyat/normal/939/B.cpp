
#include <bits/stdc++.h>

using namespace std;

long long n,k,i,mini,ans,kol;
int main()
{
  cin>>k>>n;
  mini=k+1;
  for (i=0; i<n; i++)
    {
      long long a;
      cin>>a;
      long long z=k%a;
      if (z<mini)
        {
          mini=z;
          ans=i+1;
          kol=k/a;
        }
      
      
    }

cout<<ans<<' '<<kol;



	return 0;		
}