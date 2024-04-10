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
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

int n,m,g,r;

const int maxm = 1e4+5 , maxg = 1e3+5;
//int dp[maxm][maxg];
int a[maxm],dist[maxm];
int vis[maxm][maxg];
ll inf = 1e18;

// void go(int i,int lef,int d) {
// 	if(dp[i][lef]!=-1) return;
// 	dp[i][lef]=1;
// 	if(lef==0) {

// 	}
// }


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    rep(i,m) cin>>a[i];
    sort(a,a+m);
    cin>>g>>r;
    //memset(dp,-1,sizeof(dp));
    memset(dist,-1,sizeof(dist));
    //go(0,0,0);
    int i,left,d,ld,rd,nleft;
    deque<iii> q;
    q.push_back(iii(0,0,0));
    vis[0][0]=1;
    while(!q.empty()) {
    	tie(i,left,d) = q.front();
    	//db3(i,left,d);
    	q.pop_front();
    	if(left==0) {
    		dist[i]=d;
    		q.push_back(iii(i,g,d+1));
    	} else {
    		if(i!=0) {
    			ld = a[i] - a[i-1];
    			nleft = left - ld;
    			if(nleft >= 0 && !vis[i-1][nleft]) {
    				vis[i-1][nleft] = 1;
    				q.push_front(iii(i-1, nleft, d));
    			}
    		}
    		if(i!=m-1) {
    			rd = a[i+1] - a[i];
    			nleft = left - rd;
    			if(nleft >= 0 && !vis[i+1][nleft]) {
    				vis[i+1][nleft] = 1;
    				q.push_front(iii(i+1, nleft, d));
    			}
    		}
    	}
    }
    ll ans = inf;
    ll cycle = r+g;
    rep(i,m) {
    	if(dist[i]!=-1) {
    		if(i==m-1) {
    			ans = min(ans, cycle * (dist[i]-1) + g);
    		} else if(a[m-1] - a[i] <= g) {
    			ans = min(ans, cycle * dist[i] + a[m-1] - a[i]);
    		}
    	}
    }
    if(ans == inf) cout<<-1<<endl;
    else cout<<ans<<endl;




}