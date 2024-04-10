#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int L=0,R=1000000000;
string ss;
int op;
int main()
{
	cin>>n;
	cout<<"1 0"<<endl;
	cin>>ss;
	if (ss[0]=='b') op=0;
	else op=1;
	for (int u=2;u<=n;u++)
	{
		int mid=(L+R)>>1;
		cout<<"1 "<<mid<<endl;
		cin>>ss;
		int t;
		if (ss[0]=='b') t=0;
		else t=1;
		if (t==op) L=mid;
		else R=mid;
	}
	
	cout<<"0 "<<R<<" "<<"2 "<<L<<endl;
	return 0;
}