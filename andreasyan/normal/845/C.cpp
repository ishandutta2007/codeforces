#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ban
{
	int x;
	int gm;
};
bool operator<(const ban& a,const ban& b)
{
	if(a.x<b.x)
		return true;
	if(a.x>b.x)
		return false;
	return a.gm<b.gm;
}

int n;
vector<ban> a;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ban t;
		t.x=l;
		t.gm=1;
		a.push_back(t);
		t.x=r+1;
		t.gm=-1;
		a.push_back(t);
	}
	int x=0;
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();++i)
	{
		x+=a[i].gm;
		if(x>2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
//	system("pause");
	return 0;
}