#include <iostream>
#include <vector>
using namespace std;

int n,m,k,z,x;
char a[1000003];
vector<int> ans,b;
int main()
{
	int i,j;
	cin>>n>>m>>k>>z;
	cin>>a;
	b.push_back(-1);
	for(i=0;i<n;i++)
	{
		if(a[i]=='1')
			b.push_back(i);
	}
	b.push_back(n);
	for(i=1;i<b.size();i++)
	{
		for(j=b[i-1];j<b[i];)
		{
			if(j+k>=b[i])
				break;
			ans.push_back(j+k);
			j+=k;
		}
	}
////////////////////////////////////////////
	x=ans.size();
	cout<<x-m+1<<endl;
	for(i=0;i<x-m+1;i++)
	{
		cout<<ans[i]+1<<' ';
	}
	cout<<endl;
	return 0;
}