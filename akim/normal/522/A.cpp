#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

map<string, int> ma;
vector<int> rb[maxn];

void down(string &nnm) {
	for(int i = 0; i < (int)nnm.length(); i++) {
		if(nnm[i] >= 'A' && nnm[i] <= 'Z') {
			nnm[i] -= 'A';
			nnm[i] += 'a';
		}
	}
}

int h = 0, ans = 0;

void dfs(int u) {
	h++;
	ans = max(ans, h);
	for(int i = 0; i < (int)rb[u].size(); i++) {
		dfs(rb[u][i]);
	}
	h--;
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	ma["polycarp"] = 0;
	int cnt = 1;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string newname;
		cin >> newname;
		down(newname);
		ma[newname] = cnt;
		cin >> newname;
		cin >> newname;
		down(newname);
		rb[ma[newname]].pb(cnt);
		cnt++;
	}

	dfs(0);

	cout << ans;

	return(0);
}

// by Kim Andrey