#include<bits/stdc++.h>
using namespace std;
int n,r=5000,l=5000,ll=-1,rr=-1;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='R')r=min(r,i),rr=i;
		else if(s[i]=='L')l=min(l,i),ll=i;
	}
	if(rr==-1)cout<<ll+1<<" "<<l;
	else if(ll==-1)cout<<r+1<<" "<<rr+2;
	else cout<<ll+1<<" "<<rr+2;
	return 0;
}