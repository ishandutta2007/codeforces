# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 1e5+10;

ll s[xn], d[xn], ans, sum;
int a[xn];
bool mark[xn];
vector <int> adj[xn];

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a ,  ll b){
    if(a==-1){
        return(-1);
    }
    ll gc = gcd(a , b);
    b/=gc;
    if(sum/b < a){
        return(-1);
    }
    return(a*b);
}

void DFS(int v){
	mark[v] = true;
	d[v] = 1;
	ll k = 0, m = 1e18;
	if (v != 1 and adj[v].size() == 1){
		s[v] = a[v];
		return;
	}
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u), k++;
		//s[v] += s[u];
		d[v] = lcm(d[u], d[v]);
		if (d[v] == -1){
			s[v] = 0;
			return;
		}
		m = min(m, s[u]);
	}
	//if (k == 0){
		//s[v] = a[v];
		//return;
	//}
    //if(v!=1) k--;
    if(sum / d[v] < k){
        s[v] = 0;
        return ;
    }
    s[v] = (m - (m%d[v]))*k;
    d[v]*=k;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i], sum += a[i];
	int q, w;
	for (int i=0; i<n-1; i++)
		cin >> q >> w, adj[q].push_back(w), adj[w].push_back(q);
	DFS(1);
	cout << sum-s[1] << endl;
}