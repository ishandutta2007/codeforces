#include<bits/stdc++.h>
using namespace std;
int n,c[202];
void dfs(int d)
{
	if(d==n){
		for(int i=1;i<=n;i++){
			if(c[i]==1)cout<<'R';
			if(c[i]==2)cout<<'O';
			if(c[i]==3)cout<<'Y';
			if(c[i]==4)cout<<'G';
			if(c[i]==5)cout<<'B';
			if(c[i]==6)cout<<'I';
			if(c[i]==7)cout<<'V';
		}
		exit(0);
	}
	for(int i=1;i<8;i++){
		int pd=1;
		for(int j=max(1,d-2);j<=d+4;j++)
			if(i==c[j])
				pd=0;
		if(pd)
			c[d+1]=c[d+n+1]=i,dfs(d+1);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<8;i++)
		c[i]=c[i+n]=i;
	dfs(7);
	return 0;
}