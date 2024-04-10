#include<bits/stdc++.h>
using namespace std;
int k,s[12],sum;
#define tt ttt
int main()
{
	cin>>k;
	for(int i=0;i<12;i++)cin>>s[i];
	sort(s,s+12);
	for(int i=11;i>=0;i--){
		if(sum>=k)cout<<11-i,exit(0);
		sum+=s[i];
	}
	if(sum>=k)cout<<12;
	else cout<<-1;
	return 0;
}