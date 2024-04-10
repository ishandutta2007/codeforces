#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"

const int N=1e4+5;

int n;
string s;
string a[N], b[N];
char ans[N];
int pos[N];
map<int, int> sidx, tidx;

void query(int idx)
{
	cout<<"? "<<a[idx]<<endl;
	cin>>b[idx];
}

void output(string &s)
{
	cout<<"! "<<s;
	exit(0);
}

void get()
{
	int left=n;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			for(int k=0;k<26;k++)
			{
				a[1]+=(char)('a'+i);
				a[2]+=(char)('a'+j);
				a[3]+=(char)('a'+k);
				left--;
				if(!left)
					break;
			}
			if(!left)
				break;
		}
		if(!left)
			break;
	}
	query(1);
	query(2);
	query(3);
}

int get2(int a, int b, int c)
{
	return a*1000000 + b*1000 + c;
}

void work()
{
	for(int i=0;i<n;i++)
	{
		int cur=get2(a[1][i], a[2][i], a[3][i]);
		sidx[cur]=i;
	}
	for(int i=0;i<n;i++)
	{
		int reqd=get2(b[1][i], b[2][i], b[3][i]);
		pos[i]=sidx[reqd];
	}
	for(int i=0;i<n;i++)
		ans[pos[i]]=s[i];
	cout<<"! ";
	for(int i=0;i<n;i++)
		cout<<ans[i];
}

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	get();
	work();
	return 0;
}