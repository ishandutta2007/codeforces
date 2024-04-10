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
const double EPS = 1e-8;

bool ok(double x,double y,int m,double c,double xx)
{
	bool ret = true;
	if(m==1) ret = ((xx - x) > -EPS);
	else if(m==-1)ret = ((x - xx) >-EPS);
	return ret && (fabs(y - m*x - c)<EPS);
}
int main()
{
	int a,b;
	si(a);si(b);
	double ans=-1;
	if(a<b)ans = -1;
	else if(a==b)ans = a;
	else
	{
		double p = (a-b)/2.0;
		double q = (a+b)/2.0;
		int l = 1,h = int(2e9);
		double ans1 = -1,ans2 = -1;
		double x;
		//case1
		while(l<=h)
		{
			int m = (l+h)/2;
			x = p / m;
			if(x < b)
				h = m - 1;
			else if(ok(a - 2*(m-1)*x , b , 1 , -2*x,x))
			{
				ans1 = x;
				l = m+1;
			}
			else
				h = m-1;
		}
		l = 1 , h = int(2e9);
		while(l<=h)
		{
			int m = (l+h)/2;
			x = q / m;
			if(x < b)
				h = m - 1;
			else if(ok(a - 2*(m-1)*x , b , -1 , +2*x,x))
			{
				ans2 = x;
				l = m+1;
			}
			else 
				h = m-1;
		}
		if(ans1!=-1)
			ans = ans1;
		if(ans2!=-1)
		{
			if(ans==-1)ans=ans2;
			else ans = min(ans,ans2);
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}