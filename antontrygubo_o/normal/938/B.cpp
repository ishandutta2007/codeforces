#include<bits/stdc++.h>
using namespace std;



int main()
{
   int n;
   cin>>n;
   int k;
   int minn = 1000000;
   for (int i = 0; i<n; i++) 
   {
       cin>>k;
       int t = min(fabs(500000-k), fabs(500001-k));
       minn = min(minn, t);
   }
    cout<<499999-minn;
}