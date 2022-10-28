#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, max1, dd, mm, yy;
string s;
int store[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int cache[50][2050][20];

bool check(int k)
{
   for(int i=0;i<9;i++)
   {
      if(i==2||i==5)
      {
         if(s[k+i]!='-')
            return false;
      }
      else
      {
         if(!(s[k+i]>='0'&&s[k+i]<='9'))
            return false;
      }
   }
   return true;
}

int calc(int k)
{
   return (s[k]-'0')*10 + (s[k+1]-'0');
}

int32_t main()
{
   cin>>s;
   n=s.size();
   for(int i=0;i<n-9;i++)
   {
      if(check(i))
      {  
         int date=calc(i);
         int month=calc(i+3);
         int year=calc(i+6)*100+calc(i+8);
         if(year>=2013&&year<=2015&&month>=1&&month<=12&&date>=1&&date<=store[month])
         {
            cache[date][month][year]++;
            if(cache[date][month][year]>max1)
            {
               max1=cache[date][month][year];
               dd=date;
               mm=month;
               yy=year;
            }
         }
      }
   }
   printf("%02d-%02d-%04d", dd, mm, yy); 
   return 0;
}