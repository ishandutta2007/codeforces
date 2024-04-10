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

const LL INF = LL(1e18);


int main()
{
	int n,k;
	si(n);si(k);
	int busy=0;
	multiset<pair<LL,int> > end;
	vector<pair<LL,LL> > A(n);
	for(int i=0;i<n;i++)
		sll(A[i].F),sll(A[i].S);
	A.PB(MP(INF,INF));
	
	end.insert(MP(A[0].F + A[0].S,0));
	int nxts = 1;
	LL ctime = A[0].F;
	busy = 1;
	vector<LL> ans(n);
	while(!(end.empty() && nxts == SZ(A)-1))
	{
		//trace5(ctime,nxts,A[nxts].F,busy,*end.begin());
		if(busy == k)
		{
			ctime = end.begin()->F;
			ans[end.begin()->S] = ctime;
			end.erase(end.begin());
			busy--;
			continue;
		}
		if(busy==0)
		{
			ctime = max(ctime,(LL)A[nxts].F);
			end.insert(MP(ctime + A[nxts].S,nxts));
			nxts++;
			busy++;
			continue;
		}

		if(A[nxts].F < end.begin()->F)
		{
			ctime = max(ctime,(LL)A[nxts].F);
			end.insert(MP(ctime + A[nxts].S,nxts));
			nxts++;
			busy++;
		}
		else if(A[nxts].F > end.begin()->F)
		{
			ctime = max(ctime,end.begin()->F);
			ans[end.begin()->S] = ctime;
			//cout<<"hello"<<endl;
			end.erase(end.begin());
			busy--;
		}
		else if(A[nxts].F == end.begin()->F)
		{
			ctime = max(ctime,(LL)A[nxts].F);
			ans[end.begin()->S] = ctime;
			end.erase(end.begin());
			end.insert(MP(ctime + A[nxts].S,nxts));
			nxts++;
		}
	}
	//trace1(SZ(ans));
	for(int i=0;i<SZ(ans);i++)
		lldout(ans[i]);

	return 0;
}