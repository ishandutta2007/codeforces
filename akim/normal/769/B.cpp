#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

vector <pii> ans;
int n, a[N];
bool u[N];
queue <int> q;

int main () {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	u[1] = 1;
	for(int i = 1; i <= a[1]; i++){
		q.push(1);
	}
	while(!q.empty()){
		int p = -1;
		int v = q.front();
		q.pop();
		for(int i = 1; i <= n; i++) if(!u[i]){
			if(p == -1 || a[p] < a[i]){
				p = i;
			}
		}
		if(p == -1) break;
		u[p] = 1;
		ans.pb(mp(v,p));
		for(int i = 1; i <= a[p]; i++) q.push(p);
	}
	for(int i = 1; i <= n; i++){
		if(!u[i]){
			cout << -1;
			return 0;
		}
	}
	cout << int(ans.size()) << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].f << " " << ans[i].s << endl;
	}

	


return 0;
}