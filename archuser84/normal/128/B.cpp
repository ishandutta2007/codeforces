///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 1e5+10;
const int alpha = 27;
string s;

vector<int> suffix(){
	static int cnt[N];
	memset(cnt,0,sizeof cnt);
	const int n = s.size();
	vector<int> p(n), c(n);
	Loop(i,0,n) cnt[s[i]]++;
	Loop(i,1,alpha) cnt[i]+=cnt[i-1];
	Loop(i,0,n) p[--cnt[s[i]]]=i;
	int cc=1; c[p[0]]=0;
	Loop(i,1,n) {
		if(s[p[i]]!=s[p[i-1]]) ++cc;
		c[p[i]] = cc-1;
	}
//	Loop(i,0,n) cout << c[i] << ' '; cout << '\n';
	for(int k=1; k<n; k*=2){
		memset(cnt,0,sizeof cnt);
		vector<int> pn(n), cn(n);
		Loop(i,0,n) pn[i] = p[i]-k<0?p[i]-k+n:p[i]-k;
		Loop(i,0,n) cnt[c[i]]++;
		Loop(i,1,cc) cnt[i]+=cnt[i-1];
		LoopR(i,0,n) p[--cnt[c[pn[i]]]]=pn[i];
		cc=1; cn[p[0]]=0;
		Loop(i,1,n) {
			if(c[p[i-1]] != c[p[i]] ||
			   c[(p[i-1]+k)%n] != c[(p[i]+k)%n])
				++cc;
			cn[p[i]] = cc-1;
		}
		c = cn;
//		Loop(i,0,n) cout << c[i] << ' '; cout << '\n';
	}
	return p;
}

int cur[N], gp[N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int k; cin >> s >> k; int n = s.size();
	--k; s.push_back('z'+1); for(char& c : s) c-='a';
	auto vec = suffix();
	gp[0]=n-1;
	Loop(i,0,n){
		int p = gp[i];
		Loop(len,cur[i],n-vec[i]){
			int ip=p;
			while(s[vec[p]+len] != s[vec[i]+len]) {
				cur[p]=len;
				gp[p]=ip;
				--p;
			}
			int cnt = p-i+1;
//			cout << vec[i]<<' '<<len+1<<' '<<cnt << '\n';
			if(cnt<=k) k -= cnt;
			else {
				Loop(j,vec[i],vec[i]+1+len) cout << char(s[j]+'a');
				cout << '\n';
				return 0;
			}
		}
	}
	cout << "No such line.\n";
}

//'a': 2
//'ab': 2
//'aba': 1
//'abab': 1
//'b': 2