#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> M;
const int inf = 2e9;
const ll md = 1e9+7;

int main(){
	int n,m;
	cin >> n >> m;
	if(m == n*(n-1)/2){
		cout<<"Yes\n";;
		rep(i,0,n)cout<<'a';
		cout << endl;
		return 0;
	}
	vector<bitset<500> > g(n,0);
	rep(i,0,n) g[i][i] = 1;
	rep(_,0,m){
		int u,v;
		cin >> u >> v;
		--u,--v;
		g[u][v] = g[v][u] = 1;
	}
	vector<char> s(n,'?');
	int a;
	rep(i,0,n){
		if(g[i].count() == n) s[i] = 'b';
		else a = i;
	}
	rep(i,0,n){
		if(s[i] != 'b'){
			if(g[a][i]) s[i] = 'a';
			else s[i] = 'c';
		}
	}
	rep(i,0,n) rep(j,0,n){
		if(!g[i][j] != (s[i]!='b'&&s[j]!='b'&&(s[i]!=s[j]))){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	rep(i,0,n)cout<<s[i];
	cout<<endl;
}