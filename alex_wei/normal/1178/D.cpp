#include<bits/stdc++.h>
using namespace std;
int n,m,eg[1002][1002],ss[500002],poi=1;
void pre()
{
	ss[0]=ss[1]=1;
	for(int i=2;i<500002;i++)
		if(!ss[i])
			for(int j=i+i;j<500002;j+=i)
				ss[j]=1;
}
int main()
{
	pre();
	cin>>n,m=n;
	if(n==2)cout<<-1,exit(0);
	for(int i=1;i<=n;i++)
		eg[i][i%n+1]=1;
	while(ss[m]){
		m++;
		eg[poi][poi+n/2]=1;
		poi++;
	}
	cout<<m<<endl;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(eg[i][j])
				cout<<i<<" "<<j<<endl;
	return 0;
}