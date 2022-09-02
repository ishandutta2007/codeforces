#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;


int res(int ang)
{
    for (int n = 3; n<=360; n++)
    {
        if (n*ang%180==0&&n*ang/180<n-1) return n;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
   int t;
   cin>>t;
   for (int i = 0; i<t; i++)
   {
       int ang;
       cin>>ang;
       cout<<res(ang)<<endl;
    }
}