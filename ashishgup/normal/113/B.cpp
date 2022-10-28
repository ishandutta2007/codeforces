#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

string s, a, b;
int asz, bsz, ans=0;
int lps[N];
int goodstart[N], goodend[N];
vector<int> v;

struct data
{
	int cnt=0;
	data* next[26];
};

struct data* root;

void insert(string &s, int ind)
{
	int startind=ind;
	struct data* cur=root;
	int sz=s.size();
	for(int i=0;i<sz;i++)
	{
		int ch=s[i]-'a';
		if(cur->next[ch]==NULL)
		{
			cur->next[ch]=new struct data();
		}
		if(!(cur->cnt))
		{
			if(ind-startind>=(asz-bsz)&&goodend[ind])
			{
				cur->cnt=1;
				ans++;
			}
		}
		ind++;
		cur=cur->next[ch];
	}
}


void KMP(string &str1, string &str2)
{
	v.clear();
	int n=str1.size();
	int m=str2.size();
	int i=0, j=0;
	while(i<n)
	{
		if(str2[j]==str1[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			v.push_back(i-j);
			j=lps[j-1];
		}
		else if(i<n && str2[j] != str1[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}

void computeLPS(string &str)
{
	int len=0;
	lps[0]=0;
	int i=1;
	int m=str.size();
	while(i<m)
	{
		if(str[i]==str[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
				lps[i++]=0;
		}
	}
}

int32_t main()
{
	IOS;
	root=new struct data();
	cin>>s>>a>>b;
	asz=a.size();
	bsz=b.size();
	computeLPS(a);
	KMP(s, a);
	for(auto it:v)
		goodstart[it]=1;
	computeLPS(b);
	KMP(s, b);
	for(auto it:v)
	{
		goodend[it]=1;
	}
	for(int i=0;i<s.size();i++)
	{
		if(!goodstart[i])
			continue;
		string cur=s.substr(i);
		insert(cur, i);
	}
	cout<<ans;
	return 0;
}