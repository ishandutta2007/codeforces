/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I dont know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

/*
 *  Short suffix array in O(N log N)
 *  uses MSD-radix sort
 *  0.624 sec for N<500001
 */
class Suffix_Array{
    void make_lcp(int const*s){
        for(int i=0, k=0;i<n;++i)
            if(inv[i]!=0){
                for(int j = sa[inv[i]-1];k<n&&s[i+k]==s[j+k];++k);
                lcp[inv[i]-1]=k;
                if(k)--k;
            } else k=0;
    }
    bool cmp(vector<int> const&rank,int i,int j,int l){
        return i<n-l && j<n-l && rank[i]==rank[j] && rank[i+l]==rank[j+l];
    }
    void build_SA(int const*s){
        int m = max(256LL, n);
        sa.resize(n);
        vector<int> x(n), y(n), buck(m);
        int i,j,p;
        for(i=0;i<n;++i) buck[x[i]=s[i]]++;
        for(i=1;i<m;++i) buck[i]+=buck[i-1];
        for(i=n-1;i>=0;--i) sa[--buck[x[i]]]=i;
        for(p=0,j=1;p+1<n;m=p+1,j*=2) {
            for(p=0,i=n-j;i<n;++i) y[p++]=i;
            for(i=0;i<n;++i) if (sa[i]>=j) y[p++]=sa[i]-j;
            memset(buck.data(),0,sizeof(int)*(m));
            for(i=0;i<n;++i) ++buck[x[y[i]]];
            for(i=1;i<m;++i) buck[i]+=buck[i-1];
            for(i=n-1;i>=0;--i) sa[--buck[x[y[i]]]]=y[i];
            x.swap(y);
            for(p=0,x[sa[0]]=0,i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p : ++p;
        }
        x.swap(inv); y.swap(lcp);
        for(int i=0;i<n;++i) inv[sa[i]]=i;
        make_lcp(s);
    }
    public:
    Suffix_Array(int const*s, int _N):n(_N){build_SA(s);}
    Suffix_Array(vector<int> const&s):Suffix_Array(s.data(), s.size()){}
    Suffix_Array(char const*s, int _N):n(_N){build_SA(vector<int> (s, s+n).data());}
    Suffix_Array(string const&s):Suffix_Array(s.data(), s.size()){}
    vector<int> sa, inv, lcp;
    const int n;
};
void solve() {
	int n;
	string s,t;
	cin>>n>>s>>t;
	int anst=0;
	for(int i=0; i<n; i++) {
		t[i]='1'-t[i];
		if(t[i]==1)
			anst=i+1;
	}
	Suffix_Array lol(s);
	vi pre(sz(lol.lcp),0);
	for(int i=0; i<n; i++)
		lol.sa[i]=n-1-lol.sa[i];
	for(int i=0; i<n; i++)
	{
		if(i!=0)
			pre[i]=t[lol.sa[i]]+pre[i-1];
		else
			pre[i]=t[lol.sa[i]];
	}
	stack<pii> lolol;
	vi ans(sz(lol.lcp),0);
	for(int i=0; i+1<n; i++) {
		trace(lol.lcp[i]);
		while(!lolol.empty()&&lolol.top().fi>=lol.lcp[i])
			lolol.pop();
		if(!lolol.empty())
			ans[i]=pre[i]-pre[lolol.top().se];
		else
			ans[i]=pre[i];
		trace(ans[i]);
		lolol.push({lol.lcp[i],i});
	}
	while(!lolol.empty())
		lolol.pop();
	lolol.push({-1,n-1});
	for(int i=n-2; i>=0; i--) {
		while(lolol.top().fi>=lol.lcp[i])
			lolol.pop();
		ans[i]+=pre[lolol.top().se]-pre[i];
		trace(ans[i],anst,pre[lolol.top().se],pre[i]);
		anst=max(anst,ans[i]*lol.lcp[i]);
		lolol.push({lol.lcp[i],i});
	}
	cout<<anst<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}