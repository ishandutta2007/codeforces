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
const int N = int(1e6)+10;
struct BIT{
	VI bit;int n;
	BIT(int _n){n = _n+1; bit = VI(n,0);}
	BIT(){n=0;bit.clear();}
	int query(int x){
		int ret = 0;
		for(;x;x=(x&(x-1)))
			ret+=bit[x];
		return ret;
	}
	void update(int x,int add){
		for(;x<n;x+=(x^(x&(x-1))))
			bit[x]+=add;
	}
}A[N];
struct query{
	int a,t,x;
}Q[N];
map<int,int> mp1,mp2[N];
VI q[N];
int len,lent[N];
int main()
{
	int n;si(n);
	for(int i=0;i<n;i++){
		si(Q[i].a),si(Q[i].t),si(Q[i].x);
		mp1[Q[i].x];
	}
	for(int i=0;i<N;i++)lent[i]=1;
	for(auto &it:mp1)
		it.S = len++;
	for(int i=0;i<n;i++)
		Q[i].x = mp1[Q[i].x];
	for(int i=0;i<n;i++)
		mp2[Q[i].x][Q[i].t];
	for(int i=0;i<n;i++)
		for(auto &it:mp2[i])
			it.S=lent[i]++;
	for(int i=0;i<n;i++)
		Q[i].t = mp2[Q[i].x][Q[i].t];
	for(int i=0;i<len;i++)
		A[i] = BIT(lent[i]);
	for(int i=0;i<n;i++){
		int a = Q[i].a,t = Q[i].t, x = Q[i].x;
		if(a == 1){
			A[x].update(t,+1);
		}
		else if(a == 2){
			A[x].update(t,-1);
		}
		else{
			dout(A[x].query(t));
		}
	}
	return 0;
}