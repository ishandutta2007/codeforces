#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
string s;
int main()
{
	cin>>s;
	int n=s.size();
	vector<int> ans;
	int i=0,j=n-1;
	while(1)
	{
		while(i<n&&s[i]==')')i++;
		while(j>=0&&s[j]=='(')j--;
		if(i>j)break;
		ans.push_back(i+1);
		ans.push_back(j+1);
		i++;j--;
	}
	if(!ans.size())
	{
		puts("0");
		return 0;
	}
	puts("1");
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int &x:ans)printf("%d ",x);
	return 0;
}