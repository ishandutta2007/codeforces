#include<bits/stdc++.h>
using namespace std;
int n,a[100005],st,use,l=1,r=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[++n]=1e9+1;
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1]){
			if(use)cout<<"no",exit(0);
			if(!st)st=i-1;
		}
		else if(st){
			if(a[i]<=a[st]||a[i-1]<=a[st-1])cout<<"no",exit(0);
			else l=st,r=i-1,use=1,st=0;
		}
	cout<<"yes\n"<<l<<" "<<r; 
	return 0;
}