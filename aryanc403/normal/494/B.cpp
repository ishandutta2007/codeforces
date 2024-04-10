/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (lli)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s,t;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .
#define rep(i, a, b) for(int i = a; i < (b); ++i)

void count_sort(vector<pair<lli, int>> &b, int bits) { // (optional)
	//this is just 3 times faster than stl sort for N=10^6
	int mask = (1 << bits) - 1;
    for(int it = 0; it < 2; ++it)
	{
		int move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		for(int i = 0; i < sz(b); ++i)
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pair<lli, int>> res(b.size());
        for(int i = 0; i < sz(b); ++i)
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pair<lli, int>> b(N);
		a.resize(N);
		for(int i = 0; i < N; ++i)
		{
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
			a[b[0].second] = 0;
			for(int i = 1; i < N; ++i)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			for(int i = 0; i < N; ++i)  {
				b[i].first = (lli)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	int lower_bound(string t){
		int l = 1,r=sz(a);
		while(l<r){
			int m = (l+r)/2;
			if(s.substr(a[m],min(sz(s)-1-a[m],sz(t)+1)) >= t) r = m;
			else l = m+1;
		}
		return l;
	}
	int upper_bound(string t){
		int l = 1,r=sz(a);
		while(l<r){
			int m = (l+r)/2;
			if(s.substr(a[m],min(sz(a)-1-a[m],sz(t))) > t) r = m;
			else l = m+1;
		}
		return l;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		for(int i = 0; i <n; ++i)  inv[a[i]] = i;
		for(int i = 0; i <n; ++i)  if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};


int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>s;
    cin>>t;
    SuffixArray ss(s);
    lli lb=ss.lower_bound(t);
    lli ub=ss.upper_bound(t);
    
    const lli n=sz(s),m=sz(t);
    vi dp(n+2,0),oc(n+2,0);
    vii prf(n+2);
    while(lb<ub)
    {
        // dbg(ss.a[lb],t,s.substr(ss.a[lb],sz(t)));
        oc[ss.a[lb]+m]=true;
        lb++;
    }

    dbg(oc);
    dbg(prf);
    repA(i,1,n)
    {
        dp[i]=dp[i-1];
        if(!oc[i])
        {
            cnt+=dp[i];
            prf[i].X=(prf[i-1].X+dp[i])%mod;
            prf[i].Y=(prf[i-1].Y-i*dp[i])%mod;
            continue;
        }
        // dbg(i,i-m)
        dp[i]=0;
        // repA(k,0,i-m)
        // {
        //     // dbg(k,dp[k],i-m-k+1);
        //     dp[i]+=dp[k]*(i-m-k+1)%mod;
        // }
        
        dp[i]=prf[i-m].X*(i-m+1)+prf[i-m].Y;
        dp[i]%=mod;

        dp[i]+=i-m+1;
        // dbg(i,i-m+1);
        dp[i]%=mod;
        cnt+=dp[i];


        prf[i].X=(prf[i-1].X+dp[i])%mod;
        prf[i].Y=(prf[i-1].Y-i*dp[i])%mod;
    }

    cnt=(cnt%mod+mod)%mod;
    cout<<cnt<<endl;
    
}   aryanc403();
    return 0;
}