#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans=6;
int check(int x,int y)
{
	int t[7],p=n,s=1;
	for(int i=1;i<7;i++)
		t[i]=(i==x||i==y);
	for(int i=1;i<7;i++){
		if(t[i]){
			if(p<b)p=n-b,s++;
			else p-=b;
		}
		else{
			if(p<a)p=n-a,s++;
			else p-=a;
		}
	}
	return s;
}
int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<6;i++)
		for(int j=i+1;j<7;j++)
			ans=min(ans,check(i,j));
	cout<<ans;
	return 0;
}