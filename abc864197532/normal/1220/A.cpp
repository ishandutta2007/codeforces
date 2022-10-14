#include <bits/stdc++.h>
using namespace std;

main()
{
   int n,k=0;
   cin>>n;
   string s;
   cin>>s;
   for(int i=0;i<n;i++) {
       if(s[i]=='r')
       k++;
   }
   int n0,n1;
   n0=k;
   n1=(n-4*n0)/3;
   for(int i=0;i<n1;i++) cout<<1<<' ';
   for(int i=0;i<n0;i++) cout<<0<<' ';
   cout<<endl;
}