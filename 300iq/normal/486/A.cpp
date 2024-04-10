#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long ans = 0;
   long long n;
   cin >> n;
   if(n % 2 == 0){
        cout << n / 2;
   }
   else{
        cout << "-"<< n / 2 + 1;
   }
}