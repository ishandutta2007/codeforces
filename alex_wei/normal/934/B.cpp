#include <bits/stdc++.h>
using namespace std;
int k;
int main()
{
	cin>>k;
	if(k>36)cout<<"-1",exit(0);
	if(k%2)cout<<4,k--;
	while(k)k-=2,cout<<8;
    return 0;
}