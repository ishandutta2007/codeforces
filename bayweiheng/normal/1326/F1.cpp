#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pcnt __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

int l,r,n,j;
string a[20];
const int maxs=1<<14,maxb=1<<13;
vll dp[maxs][14];
// dp[subset][end][string] stores number of ways to get string using subset ending at end

ll f(int st,int en,int nd) {
	if(dp[st][en][nd]!=-1) return dp[st][en][nd];
	ll ans=0;
	if(pcnt(st)==2) {
		int i=ctz(st),j=ctz(st-(1<<i));
		ans = nd == 1 ? a[i][j]=='1' : a[i][j]=='0';
	} else {
		int t=st-(1<<en);
		int last=nd&1;
		for(int i=t;i>0;i-=i&(-i)) {
			int j=ctz(i);
			if((last && a[en][j]=='1') || (!last && a[en][j]=='0')) ans += f(t,j,nd/2);
		}
	}
	return dp[st][en][nd]=ans;
}

ll g(int subset,int need) {
	ll ans=0;
	for(int i=subset;i>0;i-=i&(-i)) {
		int j=ctz(i);
		ans += dp[subset][j][need]; // f(subset,j,need);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
   	rep(i,n) cin>>a[i];
   	if(n<-9) {
   		vi ans(1<<(n-1),0);
   		int o[n],t;
   		rep(i,n) o[i]=i;
   		do {
   			t=0;
   			rep(i,n-1) {
   				t*=2;
   				if(a[o[i]][o[i+1]]=='1') t+=1;
   			}
   			++ans[t];
   		} while(next_permutation(o,o+n));
   		rep(i,1<<(n-1)) {
   			cout<<ans[i]<<" \n"[i==(1<<(n-1))-1];
   		}
   	} else {
   		int tgt=(1<<n)-1;
   		rep(i,tgt+1) {
   			if(pcnt(i)<2) continue;
   			rep(j,n) {
   				dp[i][j].resize(1<<(pcnt(i)-1),0);
   			}
   		}
   		int st,j,en,bit;
   		queue<int> q;
   		vi vis(1<<n,0);
   		rep(i,n) {
   			rep(j,i) {
   				st=(1<<i) | (1<<j);
   				dp[st][i][1] = dp[st][j][1] = a[i][j]=='1';
   				dp[st][i][0] = dp[st][j][0] = a[i][j]=='0';
   				vis[st]=1;
   				q.push(st);
   			}
   		}
   		while(!q.empty()) {
   			st=q.front();
   			q.pop();
   			int o=pcnt(st),x=tgt-st;
   			for(int t=x;t>0;t-=t&(-t)) {
   				j=ctz(t);
   				for(int u=st;u>0;u-=u&(-u)) {
   					en=ctz(u);
   					bit=a[en][j]=='1';
   					rep(bm,1<<(o-1)) {
   						dp[st | (1<<j)][j][(bm<<1) | bit] += dp[st][en][bm];
   					} 
   				}
   				if(!vis[st | (1<<j)]) {
   					q.push(st | (1<<j));
   					vis[st | (1<<j)] = 1;
   				}
   			}
   		}
   		rep(i,1<<(n-1)) {
   			cout<<g(tgt,i)<<" \n"[i==(1<<(n-1))-1];
   		}
   	}


}