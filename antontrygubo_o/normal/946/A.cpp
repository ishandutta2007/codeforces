#include <bits/stdc++.h>
using namespace std;


int main()
{
int n;
cin>>n;
long long sum = 0;
long long temp;
for (int i = 0; i<n; i++) {cin>>temp; sum+=fabs(temp);}
cout<<sum;
}