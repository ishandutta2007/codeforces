#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main()
{jizz
	int t,a,b,c;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> s,a=b=c=0;
		for(auto x:s)
			if(x>='0' && x<='9') ++a;
			else if(x>='A' && x<='Z') ++b;
			else if(x>='a' && x<='z') ++c;
		if(!a && b && c)
		{
			if(b>1)
			{
				for(int i=0;i<s.size();++i)
					if(s[i]>='A' && s[i]<='Z')
					{
						s[i]='0';
						break;
					}
			}
			else
				for(int i=0;i<s.size();++i)
					if(s[i]>='a' && s[i]<='z')
					{
						s[i]='0';
						break;
					}
		}
		else if(a && !b && c)
		{
			if(a>1)
			{
				for(int i=0;i<s.size();++i)
					if(s[i]>='0' && s[i]<='9')
					{
						s[i]='A';
						break;
					}
			}
			else
				for(int i=0;i<s.size();++i)
					if(s[i]>='a' && s[i]<='z')
					{
						s[i]='A';
						break;
					}
		}
		else if(a && b && !c)
		{
			if(a>1)
			{
				for(int i=0;i<s.size();++i)
					if(s[i]>='0' && s[i]<='9')
					{
						s[i]='a';
						break;
					}
			}
			else
				for(int i=0;i<s.size();++i)
					if(s[i]>='A' && s[i]<='Z')
					{
						s[i]='a';
						break;
					}
		}
		else if(!a && !b && c)
			s[0]='0',s[1]='A';
		else if(!a && b && !c)
			s[0]='0',s[1]='a';
		else if(a && !b && !c)
			s[0]='a',s[1]='A';
		else if(!a && !b && !c)
			s[0]='a',s[1]='0',s[2]='A';
		cout << s << "\n";
	}
}