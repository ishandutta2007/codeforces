#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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

int pos1[maxn], pos2[maxn];

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

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pos1[i]);
		pos1[i]--;
		pos2[pos1[i]] = i;
	}
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		int q;
		scanf("%d", &q);
		q--;
		ans += 1ll * (pos2[q] / k + 1);
		if(pos2[q] == 0) continue;
		int asd2 = pos1[pos2[q] - 1];
		swap(pos1[pos2[q]], pos1[pos2[q] - 1]);
		swap(pos2[q], pos2[asd2]);
//		for(int i = 0; i < n; i++) {
//			cout << pos1[i] + 1 <<" ";
//		}cout << endl;
	}

	cout << ans;

	return(0);
}

// by Kim Andrey