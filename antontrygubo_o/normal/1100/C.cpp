#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    

   double n, r;
   cin>>n>>r;
   double SOK = M_PI/n;
   double SK = r*tan(SOK);
   double ISK = (M_PI/2 + SOK)/2;
   double IK = SK*tan(ISK);
   cout<<setprecision(10)<<IK;
    
}