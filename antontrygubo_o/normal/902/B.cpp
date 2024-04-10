#include<iostream>

using namespace std;


int main()
{
int n;
cin>>n;
int previous[n-1];
for (int i = 0; i<n-1; i++) cin>>previous[i];
int color[n];
for (int i =0; i<n; i++) cin>>color[i];
int number = 1;
for (int i = 1; i<=n-1; i++) if(color[i]!=color[previous[i-1]-1]) number++;
cout<<number<<endl;
//for (int i = 1; i<n-1; i++) cout<<i<<' '<<color[i]<<' '<<color[rebro[i]-1]<<endl;

}