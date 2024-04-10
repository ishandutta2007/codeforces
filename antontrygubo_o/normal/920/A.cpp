#include<bits/stdc++.h>
using namespace std;


int main()
{
  int t;
  cin>>t;
  for (int i = 0; i<t; i++)
  {
      int n, k;
      cin>>n>>k;
      int a[k];
      for (int i = 0; i<k; i++) cin>>a[i];
      int maxx = 0;
      maxx = a[0];
      maxx = max(maxx, n+1-a[k-1]);
      for (int i = 0; i<k-1; i++) maxx = max(maxx, (2+a[i+1]-a[i])/2);
      cout<<maxx<<endl;
      
     
  }
}