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

const int maxn=1e5+5;
vi adj[maxn];
vi order;
int subtree_sz[maxn];

void print(vi &v) {
	for(int i:v) cerr<<i<<" ";
		cerr<<endl;
}

void dfs1(int i,int p) {
	subtree_sz[i] = 1;
	if(i!=1) adj[i].erase(find(all(adj[i]),p));
	for(int j:adj[i]) {
		if(j==p) continue;
		dfs1(j,i);
		subtree_sz[i] += subtree_sz[j];
	}
}

// void dfs(int i,int p) {
// 	order.pb(i);
// 	for(int j:adj[i]) {
// 		if(j==p) continue;
// 		dfs(j,i);
// 		order.pb(i);
// 	}
// 	//order.pb(i);
// }

vii ans;

void dfs(int i,int p,int d) {
	if(i==1) {
		ans.pb({i,0});
		int send = 1;
		for(int j:adj[i]) {
			dfs(j,i,send);
			ans.pb({i,send});
			send += 1;
		}
	} else {
		ans.pb({i,d});
		int k=d-1;
		int children = adj[i].size();
		if(children == 0) {
			ans.pb({i,k});
			return;
		}
		if(children <= k) {
			int send = k - children + 1;
			ans.pb({i,send-1});
			for(int j:adj[i]) {
				if(j==p) continue;
				dfs(j,i,send);
				ans.pb({i,send});
				++send;
			}
		} else if(k==0) {
			int send = 2;
			for(int j:adj[i]) {
				if(j==p) continue;
				dfs(j,i,send);
				ans.pb({i,send});
				++send;
			}
			ans.pb({i,0});
		} else {
			int send = k+2;
			int times = children - k;
			rep(z,times) {
				int j = adj[i][children-times+z];
				dfs(j,i,send);
				ans.pb({i,send});
				++send;
			}
			ans.pb({i,0});
			send = 1;
			rep(z,k) {
				int j = adj[i][z];
				dfs(j,i,send);
				ans.pb({i,send});
				++send;
			}
		}
		// if(k==0) {
		// 	int send = 2;
		// 	for(int j:adj[i]) {
		// 		if(j==p) continue;
		// 	}
		// }
		//cout<<i<<" "<<k<<endl;
	}
}

bool cmp(int i,int j) {
	return subtree_sz[i] > subtree_sz[j];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int u,v;
    rep(i,n-1) {
    	cin>>u>>v;
    	//--u;--v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs1(1,-1);
    rep(i,n) {
    	sort(all(adj[i]),cmp);
    }
    //dfs(1,-1);
    dfs(1,-1,0);
    //print(order);
    int i,send;
    cout<<ans.size()<<endl;
    for(ii &p: ans) {
    	tie(i,send) = p;
    	cout<<i<<" "<<send<<endl;
    }


}