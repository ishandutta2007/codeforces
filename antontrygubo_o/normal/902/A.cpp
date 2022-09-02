#include<iostream>

using namespace std;


int main()
{
int n, m;
cin>>n>>m;
int can[m] = {0};
//for (int i =0; i<n; i++) cout<<can[i]<<' ';
int a, b;
for (int i = 0; i<n; i++) {cin>>a>>b; for (int j = a; j<b; j++) can[j]=1;}
int k = 1;
for (int i =0; i<m; i++) k = k*can[i];
if (k==0) cout<<"NO";
else cout<<"YES";
//for (int i =0; i<m; i++) cout<<can[i]<<' ';



}