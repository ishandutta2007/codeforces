//Mobius_Treap
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
VI diff;
int main()
{
	fast_io;
	int n,t;
	cin>>n>>t;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++)
		if(s1[i]!=s2[i])
			diff.PB(i);
	int d=SZ(diff);
	int left=t;
	int ii=0;
	string s = s1;
	while(1)
	{
		if(t>=d)
		{
			left = t-d;
			for(int j=ii;j<SZ(diff);j++)
			{
				int i = diff[j];
				char c;
				for(c='a';c<='z';c++)
					if(c!=s1[i] && c!=s2[i])
						break;
				s[i]=c;	
			}
			int i=0;
			while(i<n && left)
			{
				if(s1[i]==s2[i])
				{
					s[i]=(s1[i]=='a'?'b':'a');
					left--;
				}
				i++;
			}
			if(!left)
				cout<<s<<endl;
			else
				dout(-1);
			return 0;
		}
		else
		{
			if(ii>=SZ(diff)-1)break;
			int i =diff[ii];
			s[i]=s2[i];
			ii+=2;
			d-=2;
			t--;
		}
	}
	dout(-1);
	return 0;
}