#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, a[N], ans[N], p[N], cnt;
map< pii, int > was;
int ask(int i, int j){
	i++, j++;
	if(i < j)
	    swap(i, j);
    if(was.count({i, j}))
        return was[{i, j}];
    cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	if(x == -1)
	    assert(0);
	return was[{i, j}] = x;
}
int get(vector< int > &p){
	if(p.size() < 500)
		return rand() % p.size();
	int mn = -1;
	for(int i = 0; i < 50; i++){
		a[i] = __builtin_popcount(ask(p[i << 1], p[i << 1 | 1]));
		if(mn == -1 || a[mn] > a[i])
			mn = i;
	}
	return mn << 1;
}
int solve(vector< int > p){     
	random_shuffle(p.begin(), p.end());
	if(p.size() == 2){
		int ind = rand() % n;
		while(true){
			if(ind == p[0] || ind == p[1]){
				ind = rand() % n;
				continue;
			}		               
			int x = ask(ind, p[0]);
			int y = ask(ind, p[1]);
			if(x == y){
				ind = rand() % n;
				continue;
			}
			if(x < y)
				return p[0];
			else
				return p[1];
		}
	}
	int ind = get(p);
	int mn = inf;
	vector< int > pp;
	pp.pb(p[ind]);

	for(int i = 0; i < p.size(); i++)
		if(i != ind){
			a[i] = ask(p[ind], p[i]);
			mn = min(mn, a[i]);
        }
	for(int i = 0; i < p.size(); i++)
		if(i != ind && a[i] == mn)
			pp.pb(p[i]);
	return solve(pp);
}
int main()
{
	cin >> n;
	vector< int > x(n);
	for(int i = 0; i < n; i++)
		x[i] = i;
	int ind = solve(x);
	for(int i = 0; i < n; i++)
		if(ind != i)
			ans[i] = ask(i, ind);
	cout << "! ";
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";	
	cout << endl;
}