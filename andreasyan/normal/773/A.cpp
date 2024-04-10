#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,i;
int main()
{
	double x,y,p,q;
	long long xx,yy,pp,qq,k;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>x>>y>>p>>q;
		if(!p)
		{
			if(x)
				cout<<"-1"<<endl;
			else
				cout<<"0"<<endl;
			continue;
		}
		if(p==q)
		{
			if(x!=y)
				cout<<"-1"<<endl;
			else
				cout<<"0"<<endl;
			continue;
		}
		k=max(ceil(x/p),ceil((y-x)/(q-p)));
		q*=k;
		p*=k;
		xx=x;
		yy=(y-x);
		pp=p;
		qq=(q-p);
		cout<<pp-xx+qq-yy<<endl;
	}
//	system("pause");
	return 0;
}