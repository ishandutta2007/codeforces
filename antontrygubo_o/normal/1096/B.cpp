#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;


int main()
{
    ios_base::sync_with_stdio(0);
    
   ll n;
   string s;
   cin>>n>>s;
   ll start = 0;
   ll finish = n-1;
   while (s[start+1]==s[start]) start++;
   while (s[finish-1]==s[finish]) finish--;
   if (s[0]==s[n-1])
   {
        cout<<((start+2)*(n-finish+1))%p;
        return 0;
   }
   else
   {
       cout<<(start+n-finish+2)%p;
   }
}