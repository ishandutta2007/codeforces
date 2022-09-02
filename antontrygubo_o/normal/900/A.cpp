#include<iostream>

using namespace std;


int main()
{
int n;
cin>>n;
int left = 0;
int right = 0;
int x, y;
for (int i =0; i<n; i++) {cin>>x>>y; if (x<0) left++; else right++;}
if ((left>1)&&(right>1)) cout<< "No";
else cout<<"Yes";
}