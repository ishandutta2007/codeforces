#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int b[3];
map<long long,long long> a;
map<long long,long long>::iterator it;
int main()
{
	int x,i;
	for(i=0;i<6;i++)
	{
		cin>>x;
		a[x]++;
	}
	if(a.size()>3)
	{
		cout<<"Alien"<<endl;
		return 0;
	}
	i=0;
	for(it=a.begin();it!=a.end();++it)
	{
		b[i]=a[it->first];
		i++;
	}
	sort(b,b+a.size());
	if(b[0]==6 || (b[0]==2 && b[1]==4))
	{
		cout<<"Elephant"<<endl;
		return 0;
	}
	if((b[0]==1 && b[1]==1 && b[2]==4) || (b[0]==1 && b[1]==5))
	{
		cout<<"Bear"<<endl;
		return 0;
	}
	cout<<"Alien"<<endl;
	return 0;
}