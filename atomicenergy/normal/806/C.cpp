#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define mp make_pair
#define pb push_back

const int N=100005;
int n;
ll a[N];
map<ll,int> ct;

bool mark[N];
ll cur[N];

bool check(int k) {
	for (int i=0; i<k; i++)
		cur[i] = 0;
	
	for (int i=0; i<n; i++)
		mark[i] = false;
		
	int update=0;
	for (int i=0; i<n; i++) {
		if (cur[update] == 0 && a[i] == 1) {
			cur[update] = 1;
			mark[i] = true;
			update = (update+1)%k;
		} else if (cur[update]*2 == a[i]) {
			cur[update] = a[i];
			mark[i] = true;
			update = (update+1)%k;
		} else if (cur[0]*2 == a[i]) {
			cur[0] = a[i];
			mark[i] = true;
			update = 1;
		}	
	}
	
	update=0;
	for (int i=n-1; i>=0; i--) {
		if (mark[i]) continue;
		if (update == k) return false;
		if (2*cur[update] < a[i]) return false;
		update++;
	}
	
	return true;
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ct[a[i]]++;
	}
	
	if (!check(ct[1])) {
		cout << "-1\n";
		return 0;
	}
	
	int lo=0,hi=ct[1];
	while (hi-lo > 1) {
		int mid = (hi+lo)/2;
		if (check(mid)) hi=mid;
		else lo=mid;
	}
	
	for (int i=hi; i<=ct[1]; i++)
		cout << i << " ";
	cout << "\n";
}