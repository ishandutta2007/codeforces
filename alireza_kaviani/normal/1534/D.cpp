#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
//#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n;
vector<int> adj[MAXN];

vector<int> ask(int v){
	if(SZ(adj[v]))	return adj[v];
	cout << "? " << v + 1 << endl;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		adj[v].push_back(x);
	}
	return adj[v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	vector<int> vec = ask(0);
	vector<int> even , odd , res;
	for(int i = 0 ; i < n ; i++){
		if(vec[i] % 2 == 0)	even.push_back(i);
		else	odd.push_back(i);
	}
	if(SZ(even) <= SZ(odd))	res = even;
	else	res = odd;
	vector<pii> ans;
	for(int i : res){
		vector<int> v = ask(i);
		for(int j = 0 ; j < n ; j++){
			if(v[j] == 1)	ans.push_back({i + 1 , j + 1});
		}
	}
	cout << "!" << endl;
	for(pii i : ans)	cout << i.X << sep << i.Y << endl;

    return 0;
}
/*

*/