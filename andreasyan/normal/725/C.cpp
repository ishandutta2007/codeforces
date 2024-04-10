#include <iostream>
#include <vector>
using namespace std;

char a[30];
vector<char> bs,bv;
int n,m,k1,k2,x,y;
int main()
{
	int i,j,q;
	cin>>a;
	for(i=0;i<27;i++)
	{
		if(i-1>=0 && a[i]==a[i-1])
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{
				k1=j;
				k2=i;
			}
		}
	}
	for(i=k2+1;i<27;i++)
		bv.push_back(a[i]);
	for(i=0;i<k1;i++)
		bs.push_back(a[i]);
	q=0;
	for(i=k1+(k2-k1+1)/2;i<k2;i++)
	{
		cout<<a[i];
		q++;
	}
	for(i=q;i<13;i++)
	{
		if(bv.empty())
		{
			cout<<bs[0];
			bs.erase(bs.begin());
			continue;
		}
		cout<<bv[0];
		bv.erase(bv.begin());
	}
	cout<<endl;
	q=0;
	for(i=k1+(k2-k1-1)/2;i>=k1;i--)
	{
		cout<<a[i];
		q++;
	}
	for(i=q;i<13;i++)
	{
		if(bs.empty())
		{
			cout<<bv[bv.size()-1];
			bv.pop_back();
			continue;
		}
		cout<<bs[bs.size()-1];
		bs.pop_back();
	}
	cout<<endl;
	return 0;
}