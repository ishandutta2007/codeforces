//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
int main()
{
	int n,m;
	si(n);si(m);
	string s;
	cin>>s;
	bool in=false;
	int ans=0,len=0;
	for(int i=0;i<SZ(s);i++)
	{
		if(s[i]=='.')
		{
			len++;
			if(in)continue;
			in = true;
		}
		else 
		{
			if(!in)continue;
			in=false;
			ans+=len-1;
			len=0;
		}
	}
	if(in)
		ans+=len-1;
	while(m--)
	{
		int x;char c;
		cin>>x>>c;
		x--;
		if(s[x]=='.' && c=='.');
		else if(s[x]!='.' && c!='.');
		else if(s[x]=='.' && ((x>0 && s[x-1]=='.') && (x<n-1 && s[x+1]=='.')))
			ans-=2;
		else if(s[x]=='.' && ((x>0 && s[x-1]=='.') || (x<n-1 && s[x+1]=='.')))
			ans--;
		else if(s[x]!='.' && ((x>0 && s[x-1]=='.') && (x<n-1 && s[x+1]=='.')))
			ans+=2;
		else if(s[x]!='.' && ((x>0 && s[x-1]=='.') || (x<n-1 && s[x+1]=='.')))
			ans++;
		dout(ans);
		s[x]=c;
	}
	return 0;
}