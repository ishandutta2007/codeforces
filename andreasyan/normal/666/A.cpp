#include <iostream>
#include <set>
#include <string>
using namespace std;

char a[10010];
bool c[10010][4];
int n,m,k;
string s;
set<string> b;
set<string>::iterator j;
void funkc(int i,int q)
{
	if(i==5)
		return;
	if(i==n-2)
		funkc(i-1,2);
	s="";
	if(i-1>=5 && i!=n-2 && (a[i-1]!=a[i+1] || a[i+2]!=a[i] || q==3))
	{
		s.push_back(a[i-1]);
		s.push_back(a[i]);
		b.insert(s);
		if(c[i-2][2]==false)
		{
			c[i-2][2]=true;
			funkc(i-2,2);
		}
	}
	s="";
	if(i-2>=5 && i!=n-2 && (a[i+3]!=a[i] || a[i+2]!=a[i-1] || a[i-2]!=a[i+1] || q==2))
	{
		s.push_back(a[i-2]);
		s.push_back(a[i-1]);
		s.push_back(a[i]);
		b.insert(s);
		if(c[i-3][3]==false)
		{
			c[i-3][3]=true;
			funkc(i-3,3);
		}
	}
}
int main()
{
	int i;
	cin>>a;
	n=strlen(a);
	if(n<=6)
	{
		cout<<0<<endl;
		return 0;
	}
	funkc(n-1,0);
	m=b.size();
	cout<<m<<endl;
	for(j=b.begin();j!=b.end();++j)
	{
		s=*j;
		cout<<s<<endl;
	}
	return 0;
}