#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, m ,p;
char a[N];
int l[N], r[N], match[N], del[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	stack<int> st;
	for(int i=1;i<=n;i++)
	{
		l[i]=i-1;
		r[i]=i+1;
		if(a[i]=='(')
		{
			st.push(i);
		}
		else
		{
			int idx=st.top();
			st.pop();
			match[idx]=i;
			match[i]=idx;
		}
	}
	int cur=p;
	while(m--)
	{
		char ch;
		cin>>ch;
		if(ch=='R')
			cur=r[cur];
		else if(ch=='L')
			cur=l[cur];
		else
		{
			int idx1=cur;
			int idx2=match[cur];
			if(idx1>idx2)
				swap(idx1, idx2);
			l[r[idx2]]=l[idx1];
			r[l[idx1]]=r[idx2];
			cur=r[idx2];
			if(cur>n)
				cur=l[idx1];
			del[idx1]=1;
			del[idx2]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(del[i])
		{
			i=match[i];
			continue;
		}
		if(match[i]>i)
			cout<<"(";
		else
			cout<<")";
	}
	return 0;
}