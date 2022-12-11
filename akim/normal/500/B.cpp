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
const int maxn = 350;

int n;
int x[maxn];
string s[maxn];
vector<int> eks[maxn];
int vks[maxn];
int pm[maxn];
int ks = 0;

void dfs(int u) {
	pm[u] = ks;
	eks[ks].pb(x[u]);
	for(int i = 0; i < n; i++) {
		if(s[u][i] == '1' && pm[i] == 0) {
			dfs(i);
		}
	}
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

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		if(pm[i] == 0) {
			ks++;
			dfs(i);
		}
	}

	for(int i = 0; i < n; i++) {
		sort(eks[i].begin(), eks[i].end());
	}

	for(int i = 0; i < n; i++) {
		cout << eks[pm[i]][vks[pm[i]]++] << " ";
	}


	return(0);
}

// by Kim Andrey