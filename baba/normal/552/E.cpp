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

LL eval(int start,int end,string &s)
{
	stack<LL> st;
	int flag=1;
	for(int i=0;i<start;i++)
		if(s[i]=='*')
			flag=0;
		else if(s[i]=='+')
			flag=1;
		else if(flag==0)
		{
			flag=1;
			LL tp = st.top();
			st.pop();
			st.push(tp*(s[i]-'0'));
		}
		else
			st.push(s[i]-'0');
	LL num=0;
	int flag2=1;
	stack<LL> st2;
	for(int i=start;i<=end;i++)
	{
		if(s[i]=='*')
			flag2=0;
		else if(s[i]=='+')
			flag2=1;
		else if(flag2==0)
		{
			flag2=1;
			LL tp = st2.top();
			st2.pop();
			st2.push(tp*(s[i]-'0'));
		}
		else
			st2.push(s[i]-'0');
	}
	while(!st2.empty())
	{
		num+=st2.top();
		st2.pop();
	}
	if(flag==0)
	{
		flag=1;
		LL tp = st.top();
		st.pop();
		st.push(tp*num);
	}
	else
		st.push(num);
	for(int i=end+1;i<SZ(s);i++)
		if(s[i]=='*')
			flag=0;
		else if(s[i]=='+')
			flag=1;
		else if(flag==0)
		{
			flag=1;
			LL tp = st.top();
			st.pop();
			st.push(tp*(s[i]-'0'));
		}
		else
			st.push(s[i]-'0');
	LL ret=0;
	while(!st.empty())
	{
		ret+=st.top();
		st.pop();
	}
	return ret;
}
int main()
{
	string s;
	cin>>s;
	VI m;
	m.PB(-1);
	for(int i=0;i<SZ(s);i++)
		if(s[i]=='*')
			m.PB(i);
	m.PB(SZ(s));
	LL mx=0;
	for(int i=0;i<SZ(m);i++)
		for(int j=i+1;j<SZ(m);j++)
			mx = max(mx,eval(m[i]+1,m[j]-1,s));
	lldout(mx);
	return 0;
}