#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N=100005;
long long pat(string s)
{
	int m=s.size();
	int p=0;
	long long ans=0;
	for(int i=0;i<m;++i)
	{
		if(s[i]=='s')
			++p;
		else
			ans+=p;
	}
	return ans;
}
struct ban
{
	string c;
};
bool operator<(const ban& a,const ban& b)
{
	return pat(a.c+b.c)<pat(b.c+a.c);
}

int n;
ban a[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i].c;
	}
	sort(a,a+n);
	string s;
	for(int i=n-1;i>=0;--i)
	{
		s+=a[i].c;
	}
	cout<<pat(s)<<endl;
//	system("pause");
	return 0;
}