#include <bits/stdc++.h>
using namespace std;
 
//DEFINE and TYPEDEF--------------------------------------------------------------
// For actual content check from line 85

#define FORG(i,a,n) for(lld i=(lld)a;a<n?i<(lld)n:(lld)n<i;a<n?++i:--i) //for - general
#define FORZ(i,n) for(lld i=0;i<(lld)n;++i) //for - zero
#define FORGI(i,a,n,inc) for(lld i=(lld)a;a<n?i<(lld)n:(lld)n<i;a<n?i+=inc:i-=inc) //for - general incremental
#define FORZI(i,n,inc) for(lld i=0;i<(lld)n;i+=inc) //for - zero incremental
#define SPEEDUP ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define MEM(a,val) memset(a,val,sizeof(a));
 
#define all(m) m.begin(),m.end()
#define sz(m) (lld)m.size()
 
#define st first
#define nd second
#define pb push_back
#define DEC(x) fixed<<setprecision(x)
 
typedef long long int lld;
typedef unsigned long long int ulld;
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.st>>a.nd;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.st<<" "<<a.nd;return out;}
template<typename T, typename U> static inline void amin(T &x, U y){if(y<x) x=y;}
template<typename T, typename U> static inline void amax(T &x, U y){if(x<y) x=y;}

//DEBUGGER------------------------------------------------------------------------
// #define DEBUG(x) cerr<<(#x)<<" is "<<(x)<<"\n" //to debug values of variables
#define DEBUGON
#define ZINDA cerr<<"\nIdhar-ich hai apun!!\n"; //to debug if code reached that point

#ifdef DEBUGON
	vector<string> vec_splitter(string s) 
	{
		for(char& c: s) c = c == ',' ?  ' ': c;
		stringstream ss; ss << s;
		vector<string> res;
		for(string z; ss >> z; res.push_back(z));
		return res;
	}

	void debug_out(vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
	template <typename Head, typename... Tail>
		void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) 
		{
			if(idx > 0) cerr << ", "; 
			else cerr << "Line(" << LINE_NUM << "): ";
			stringstream ss; ss << H;
			cerr << args[idx] << " = " << ss.str();
			debug_out(args, idx + 1, LINE_NUM, T...);
		}

	#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__);
	#define DEBUG(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__);
#else
	#define debug(...) 320;
	#define DEBUG(...) 320;
#endif

lld power(lld b, lld e)
{
	assert(e>=0);
    if(e==0) return 1;
    if(e%2==1) return b*power(b*b,(e-1)/2);
    else return power(b*b,e/2);
}
 
lld power(lld b, lld e, lld m)
{
	assert(e>=0);
	if(e==0) return 1;
	if(e%2==1) return b*power(((b%m)*(b%m))%m,(e-1)/2,m)%m;
	else return power(((b%m)*(b%m))%m,e/2,m)%m;
}

#define endl '\n'
const long double pi = acos(-1);
constexpr int mod = 1e9+7; // 1000000007

//endl : changed to '\n', to flush comment that definition
//--------------------------------------------------------------------------------

void swagWaalaFunction()
{
	lld n;
	cin>>n;

	cout<<lld((n+1)/2 + (n+1)%2)<<endl;
	return;
}

int main()
{
    SPEEDUP;
 	lld tc=1;
 	cin>>tc;

 	#ifdef PRIMES
 		sieve();
 	#endif

 	#ifdef CHOOSE
 		nCrModInit();
 	#endif

	FORZ(i,tc)
 	{
 		// cout<<"Case #"<<i+1<<": ";
 		swagWaalaFunction();
	}
	
	// cerr<<"\n"<<timeKyaHorhaH; 	
 	return 0;
}