#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
vector < int > v[111111];
bool check(int l, int r, int x){
	int tl = 0, tr = v[x].size()-1;
	while(tl <= tr) {
		int mid = (tl+tr) >> 1;
		if(v[x][mid] > r) tr = mid-1;
		else if(v[x][mid] < l) tl=mid+1;
		else return 0;
	}
	return 1;
}
int main () {
	int a[111111], n, k, ans = 0;	
	cin >> n >> k;
	for(int i = 0; i<n; i++){
		cin >> a[i];
		v[a[i]].pb(i);
		if(v[a[i]].size() == 1) ans++;
	}
	if(ans < k){
		cout <<"-1 -1";
		return 0;
	}
	int l = 0, r = n-1;
	while(ans >= k){
		int x = a[l], get = check(l+1, n-1, x);
		if(get) {
			if(ans == k) break;
			ans--;
		}
		l++;
	}
	while(ans >= k){
		int x = a[r], get = check(l, r-1, x);
		if(get) {
			if(ans == k) break;
			ans--;
		}
		r--;
	}
	cout << l+1 << " "  << r+1;
	return 0;
}