#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
   int n;
   cin>>n;
   vector<int> l(n);
   vector<int> r(n);
   for (int i = 0; i<n; i++) {cin>>l[i]>>r[i];}
   int idxl;
   int maxl = -1;
   int idxr;
   int minr = 1000000001;
   for (int i = 0; i<n; i++)
   {
       if (l[i]>maxl) {maxl = l[i]; idxl = i;}
       if (r[i]<minr) {minr = r[i]; idxr = i;}
   }
   int best = minr-maxl;
   maxl = -1;
   minr = 1000000001;
    for (int i = 0; i<n; i++)
   {
       if (i!=idxl)
       {
          
           if (l[i]>maxl) {maxl = l[i];}
           if (r[i]<minr) {minr = r[i];} 
       }
   }
   if (minr-maxl>best) best = minr-maxl;
       maxl = -1;
   minr = 1000000001;
    for (int i = 0; i<n; i++)
   {
       if (i!=idxr)
       {if (l[i]>maxl) {maxl = l[i];}
       if (r[i]<minr) {minr = r[i];}}
   }
   if (minr-maxl>best) best = minr-maxl;  
   cout<<max(best, 0);
}