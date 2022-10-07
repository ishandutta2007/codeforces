#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int inf = 1e9;


bool z[maxn];
int a[maxn];
int cnt[maxn];
set < int > q;


void solve(vector < pair < int, int > > c){
	int d;
	d = *q.rbegin();
	q.erase(d);
	int cnt2 = c.size() - cnt[d];
	int cnt1 = 0;
	for (int i = 0; i < (int)c.size(); i++){
		if (c[i].fr == d){
			if (cnt1 < cnt2)
				z[c[i].sc] = 1;
			else
				break;
		}
		else{
			cnt1++;
			cnt2--;
		}		
	}
	
	vector < pair < int, int > > cc;
	for (int i = 0; i < (int)c.size(); i++)
		if (c[i].fr != d)
			cc.pb(c[i]);
	if ((int)cc.size() > 0)
		solve(cc);
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i] = (a[i] < 0) ? -a[i]: a[i];
		cnt[a[i]]++;		
		q.insert(a[i]);		
	}
	
	
	vector < pair < int, int > > c; 
	c.clear();
	for (int i = 0; i < n; i++)
		c.pb(mp(a[i], i));
	solve(c);	
	for (int i = 0; i < n; i++)
		if (z[i])
			a[i] = -a[i];
	
// 	for (int i = 0; i < n; i++)
// 		cerr << a[i] << " ";
// 	cerr << endl;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans += a[i] > a[j];
		
	cout << ans << "\n";
	
 
    return 0;
}