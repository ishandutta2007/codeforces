#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


int main()
{
ios_base::sync_with_stdio(0);
int n;
cin>>n;
vector<int> people(n);
vector<int> kogot(n);
for (int i = 0; i<n; i++) {cin>>kogot[i]; kogot[i]=min(i, kogot[i]);}
int number = 0;
for (int i =n-1; i>0; i--) {if (kogot[i]) people[i-1] = 1; number+= people[i-1]; kogot[i-1] = max(kogot[i-1], kogot[i]-1);}
cout<<n-number;
}