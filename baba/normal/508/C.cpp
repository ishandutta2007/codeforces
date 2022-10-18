//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;
typedef vector< vi > 	vvi;
#define lli long long int
#define ulli unsigned long long int

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
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; din(t); while(t--)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define INF 1000000000  //1 billion (10^9) 

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
	int m,t,r;
	int ans;
	din(m);din(t);din(r);
	vi arr(m);
	for(int i=0;i<m;i++)
		din(arr[i]);
	sort(ALL(arr));

	if(t<r){
		dout(-1);
		return 0;
	}

	ans = r;
	vi time(r);
	time[0]=arr[0]-r;
	for(int i=1;i<r;i++)
		time[i] = time[i-1]+1;

	for(int i=1;i<m;i++)
	{
		int ghostTime = arr[i];
		
		int placed = 0;
		for(int j=0;j<r;j++)
		{
			if(time[j]+t < ghostTime)
			{
				placed++;
				time[j] = ghostTime - placed;
				if(time[j]<arr[i-1]){
					ans = -1;
					break;
				}
			}
			else
				break;
		}



/*
		int len=0;
		while(ghostTime>time[len] && len<r)
		{
			len++;
			ans++;
		}





		for(int j=0;j<r;j++)
		{
			if(ghostTime<time[j])
			{
				ans+=j;
				for(int k=0;k<j;k++){
					for(int l = i-1;l>=0;l--)
						if(arr[l]!=ghostTime-(k+1))
							break;
					arr[k] = ghostTime - (k+1) + t;
				break;
			}
			else if(ghostTime == time[j])
			{
				
			}

		}
		*/
		if(ans == -1)
			break;
		ans+=placed;
		sort(ALL(time));
	//	trace2(ans,ghostTime);
	//	for(int j=0;j<r;j++)
	//		trace1(time[j]);
	}

	dout(ans);

	return 0;
}