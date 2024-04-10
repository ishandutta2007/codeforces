#include<bits/stdc++.h>
using namespace std;
int k,r;
int main()
{
	cin>>k>>r;
	for(int i=1;i<11;i++)if((k*i)%10==0||(k*i)%10==r)cout<<i,exit(0);
    return 0;
}