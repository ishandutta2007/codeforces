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
multiset<int> A;
VI ans;
int median()
{
	int n = SZ(A);
	int cnt=0;
	for(multiset<int>::iterator it = A.begin();it!=A.end();it++,cnt++)
		if(cnt == n/2)
			return *it;
}
int main()
{
	int n,k,p,x,y;
	cin>>n>>k>>p>>x>>y;
	int sum=0;
	for(int i=0;i<k;i++)
	{
		int in;
		si(in);
		sum+=in;
		A.insert(in);
	}
	if(sum > x)
	{
		printf("-1\n");
		return 0;
	}
	int add = x-sum;
	int left = n-k;
	while(add >= 0 && left)
	{
		int m = median();
		if(m >= y)
		{
			if(left>1)
			{
				ans.PB(1);
				A.insert(1);
				add-=1;
			}
			else if(left == 1)
			{
				int elem;
				int cnt = 0;
				for(multiset<int>::iterator it = A.begin();it!=A.end();it++,cnt++)
					if(cnt == SZ(A)/2 -1)
						elem = *it;
				if(elem>=y)
				{
					A.insert(1);
					ans.PB(1);
					add-=1;
				}
				else
				{
					A.insert(y);
					ans.PB(y);
					add -= y;
				}


			}
		}
		else if(m < y)
		{
			ans.PB(y);
			A.insert(y);
			add -= y;
		}
		left--;
	}
	if(add < 0 || median()<y)
	{
		dout(-1);
		return 0;
	}
	for(int i=0;i<SZ(ans);i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}