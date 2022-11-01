#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <math.h> 
#include <iomanip>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forrb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forrb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forrb(i,n-1,m-1,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,arr) forib(i,arr.size())
#define into(i) cin >> i;
#define def(i) int i; into(i)
#define deft(t,i) t i; into(i)
#define defn def(n)
#define defp def(p)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define defd def(d)
#define vec(a) vector<a>
#define co cout <<
#define out(a) cout << a <<' ';
#define el << endl;
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 1000000013
#define mod %998244353;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);
	defn
		veci type(n);
	vector<point> inputs(n);
	veci ans;
	fori(i, n) {
		deft(string,name)
		if (name == "AND") {
			type[i] = 1;
		}
		if (name == "OR") {
			type[i] = 2;
		}
		if (name == "XOR") {
			type[i] = 3;
		}
		if (name == "NOT") {
			type[i] = 4;
		}
		if (name == "IN") {
			type[i] = 5;
			ans.push_back(i);
		}
		if (type[i] <= 3) {
			defa defb
				a--; b--;
				inputs[i] = make_pair(a, b);
		}
		else {
			defa
				if (type[i] == 4) {
					a--;
				}
			inputs[i] = make_pair(a, -1);
		}
	}
	veci order;
	qii bfs;
	bfs.push(0);
	wne(bfs) {
		int me = bfs.front();
		bfs.pop();
		order.push_back(me);
		if (type[me] <= 3) {
			bfs.push(inputs[me].first);
			bfs.push(inputs[me].second);
		}
		if (type[me] == 4) {
			bfs.push(inputs[me].first);
		}
	}
	veci regular(n);
	forinb(i, order) {
		int me = order[i];
		if (type[me] == 5) {
			regular[me] = inputs[me].first;
		}
		if (type[me] == 4) {
			regular[me] = 1-regular[inputs[me].first];
		}
		if (type[me] == 3) {
			regular[me] = (regular[inputs[me].first] + regular[inputs[me].second])%2;
		}
		if (type[me] == 1) {
			if (regular[inputs[me].first] == 1 && 1 == regular[inputs[me].second]) {
				regular[me] = 1;
			}
			else {
				regular[me] = 0;
			}
		}
		if (type[me] == 2) {
			if (regular[inputs[me].first] == 0 && 0 == regular[inputs[me].second]) {
				regular[me] = 0;
			}
			else {
				regular[me] = 1;
			}
		}
	}
	vector<veci*> changes(n);
	forinb(i, order) {
		int me = order[i];
		if (type[me] == 5) {
			changes[me] = (new veci);
			changes[me]->push_back(me);
			con
		}
		int state = 0;
		int l = inputs[me].first;
		int r = inputs[me].second;
		if (type[me] == 4) {
			state = 1;
		}
		if (type[me] == 3) {
			state = 0;
			
		}
		if (type[me] == 1) {
			if (regular[r] == 1 && regular[l]==1) {
				state = 0;
			}
			if (regular[r] == 1 && regular[l] == 0) {
				state = 1;
			}
			if (regular[r] == 0 && regular[l] == 1) {
				state = 2;
			}
			if (regular[r] == 0 && regular[l] == 0) {
				state = 3;
			}
		}
		if (type[me] == 2) {
			if (regular[r] == 1 && regular[l] == 1) {
				state = 3;
			}
			if (regular[r] == 1 && regular[l] == 0) {
				state = 2;
			}
			if (regular[r] == 0 && regular[l] == 1) {
				state = 1;
			}
			if (regular[r] == 0 && regular[l] == 0) {
				state = 0;
			}
		}
		if (state == 0) {
			if (changes[l]->size() < changes[r]->size()) {
				changes[me] = changes[r];
				changes[me]->insert(changes[me]->end(), changes[l]->begin(), changes[l]->end());
			}
			else {
				changes[me] = changes[l];
				changes[me]->insert(changes[me]->end(), changes[r]->begin(), changes[r]->end());
			}
		}
		if (state == 1) {
			changes[me] = changes[l];
		}
		if (state == 2) {
			changes[me] = changes[r];
		}
		if (state == 3) {
			veci dummy;
			changes[me] = &dummy;
		}
	}
	veci bork = *changes[0];
	sort(all(bork));
	int i = 0;
	int j = 0;
	while (i < ans.size()&&j<bork.size()) {
		if (bork[j] < ans[i]) {
			j++;
			con
		}
		if (bork[j] == ans[i]) {
			co 1 - regular[0];
		}
		else {
			co regular[0];
		}
		i++;
	}
	while (i < ans.size()) {
		co regular[0];
		i++;
	}
	co "" el
	ex
}