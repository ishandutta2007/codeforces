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

priority_queue<pair<int, vector<int> > > q;

vector<int> vc;

void rek(int pos, ll n) {
	if(n == pos) {
		ll val = 0;
		for(int i = 0; i < n; i++) {
			int l = i, r = i;
			while(l >= 0 && vc[l] <= vc[i]) {
				l--;
			}
			while(r < n && vc[r] <= vc[i]) {
				r++;
			}
			val += (-vc[i]) * (i - l) * (r - i);
		}
		q.push(mp(val, vc));
		return;
	}
	for(int i = pos; i < n; i++) {
		swap(vc[pos], vc[i]);
		rek(pos + 1, n);
		swap(vc[pos], vc[i]);
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

	for(int i = 1; i <= 50; i++) vc.pb(-i);

	ll n, m;
	scanf("%I64d%I64d", &n, &m);
	rek(0, n);

	m--;

	while(m > 0) {
		m--; q.pop();
	}
//	while(!q.empty()) {
//		cout << q.top().fs << "---";
		for(int i = 0; i < n; i++) {
			cout << -q.top().sc[i] << " ";
		}cout << endl;
//		q.pop();
//	}

	return(0);
}

// by Kim Andrey