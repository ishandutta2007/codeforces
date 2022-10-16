#include<bits/stdc++.h>
using namespace std;
int n,t[100002],k,l,r,ll,rr;
int main()
{
	cin>>n,r=n-1;
	for(int i=0;i<n;i++)
		cin>>t[i];
	while(l<r){
		int tim=min(t[l],t[r]);
		t[l]-=tim,t[r]-=tim;
		if(!t[l])l++,ll++;
		if(!t[r])r--,rr++;
		if(l==r-1){ll++,rr++;break;}
	}
	if(l==r)ll++;
	cout<<ll<<" "<<rr;
    return 0;
}