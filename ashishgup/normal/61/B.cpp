#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;

int n;
set<string> s;
string a[5], b[N];

void solve()
{
   for(int i=1;i<=3;i++)
   {
      string reduced="";
      for(char ch:a[i])
         if(isalpha(ch))
            reduced+=tolower(ch);
      a[i]=reduced;
   }
   sort(a+1, a+4);
   do
   {
      string cur=a[1]+a[2]+a[3];
      s.insert(cur);
   }while(next_permutation(a+1, a+4));
   for(int i=1;i<=n;i++)
   {
      string reduced="";
      for(char ch:b[i])
         if(isalpha(ch))
            reduced+=tolower(ch);
      if(s.find(reduced)!=s.end())
         cout<<"ACC";
      else
         cout<<"WA";
      cout<<endl;
   }
}

int32_t main()
{
   IOS;
   cin>>a[1]>>a[2]>>a[3];
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>b[i];
   }
   solve();
   return 0;   
}