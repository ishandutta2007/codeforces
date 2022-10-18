//Tanuj Khattar
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

char s[1000];VI ans;
int n,c;
bool check(VI sign)
{
	ans = VI(SZ(sign),0);
	int sum = n*sign[0];
	for(int i=0;i<SZ(sign);i++)
		if(sign[i]==-1)
		{
			ans[i]=1;
			sum++;
		}
	int cnt = 0;
	for(int i=0;i<SZ(ans);i++)
		if(!ans[i])
			cnt++;
	if(sum<0)return false;
	int add = (cnt?sum/cnt:0);
	//trace(add,sum,cnt);
	VI pos;
	for(int i=0;i<SZ(ans);i++)
		if(!ans[i])
		{
			ans[i]=min(n,add);
			sum-=add;pos.PB(i);
			//trace(i,sum,ans[i]);
		}
	for(auto i:pos)
		{
			int x = min(n-ans[i],sum);
			ans[i]+=x;sum-=x;
		}
	bool ok = true;
	int val = 0;
	for(int i=0;i<SZ(sign);i++)
	{
		val += sign[i]*ans[i];
	//	trace(ans[i]);
		if(ans[i]>n || !ans[i])ok=false;
	}
	//trace(val,ok);
	if(val!=sign[0]*n)ok=false;
	return ok;
}
void go(VI sign)
{
		puts("Possible");
		//printf("%d ",ans[0]);
		for(int i=0;i<SZ(sign);i++)
		{
			if(i && sign[i]==1)printf("+ ");
			else if(i) printf("- ");
			printf("%d ",ans[i]);
		}
		printf("= %d\n",n);
}
int main()
{
	int len = 0;
	while((c=getchar())!='=')
		s[len++]=c;
	scanf("%d",&n);
	VI sign;ans.clear();sign.PB(1);
	for(int i=0;i<len;i++)
		if(s[i]=='+')sign.PB(1);
		else if(s[i]=='-')sign.PB(-1);
	if(check(sign))return (go(sign),0);
	for(int i=0;i<SZ(sign);i++)
		sign[i]*=-1;
	if(check(sign))
	{
		for(int i=0;i<SZ(sign);i++)
			sign[i]*=-1;
		return (go(sign),0);
	}
	puts("Impossible");
	return 0;
}