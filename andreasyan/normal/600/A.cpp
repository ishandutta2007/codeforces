#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int N=100005;

int n,m;
char a[N];
string s;
vector<string> ans1,ans2;
void stg(string b)
{
	int i,j,k;
	if(s=="0")
	{
		ans1.push_back(s);
		return;
	}
	if(s=="" || s[0]=='0')
	{
		ans2.push_back(s);
		return;
	}
	bool z=true;
	m=s.size();
	for(i=0;i<m;++i)
	{
		if(s[i]>='0' && s[i]<='9')
			continue;
		z=false;
		break;
	}
	if(z)
		ans1.push_back(s);
	else
		ans2.push_back(s);
}
int main()
{
	int i,j,k;
	cin>>a;
	n=strlen(a);
	for(i=0;i<n;++i)
	{
		if(a[i]==',' || a[i]==';')
		{
			stg(s);
			s.clear();
		}
		else
			s+=a[i];
	}
	stg(s);
	//output;
	if(ans1.empty())
		cout<<'-'<<endl;
	else
	{
		cout<<'"';
		for(i=0;i<ans1.size()-1;++i)
			cout<<ans1[i]<<',';
		cout<<ans1[ans1.size()-1]<<'"';
		cout<<endl;
	}
	//
	if(ans2.empty())
		cout<<'-'<<endl;
	else
	{
		cout<<'"';
		for(i=0;i<ans2.size()-1;++i)
			cout<<ans2[i]<<',';
		cout<<ans2[ans2.size()-1]<<'"';
		cout<<endl;
	}
	return 0;
}