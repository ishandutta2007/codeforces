#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> ans;
int funkc(int x)
{
	int res=0;
	while(x)
	{
		res+=(x%10);
		x/=10;
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=1;i<100;++i)
	{
		if((n-i)>0 && funkc(n-i)==i)
		{
			ans.push_back(n-i);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i)
		cout<<ans[i]<<' ';
	cout<<endl;
//	system("pause");
	return  0;
}