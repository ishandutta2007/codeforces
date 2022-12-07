#include <bits/stdc++.h>

using namespace std;

int n, k;

int ran()
{
	return (long long)rand()*rand()%(n+1);
}

int rel(int x)
{
	while(x>n) x-=n;
	while(x<0) x+=n;
	return x;
}

void ask(int x)
{
	cout<<"? "<<x<<endl;
}

int main()
{
	srand(3447);
	cin>>n>>k;
	int x=k;
	int p=0;
	while(x>=k)
	{
		p=ran()%n+1;
		ask(p);
		cin>>x;
	}
	int bj=1;
	while(true)
	{
		ask(rel(p+bj));
		cin>>x;
		if(bj*4>n || x>=k) break;
		bj<<=1;
	}
	p=rel(p+bj/2);
	while(bj)
	{
		ask(rel(p+bj));
		cin>>x;
		if(x<k) p=rel(p+bj);
		bj>>=1;
	}
	cout<<"! "<<rel(p+1)<<endl;
	return 0;
}