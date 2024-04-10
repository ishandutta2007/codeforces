
// Problem : E. Rest In The Shades
// Contest : Codeforces - Educational Codeforces Round 48 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1016/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[200005];
int pre[200005];

int bs(long double fnd){
	int l = 1, r = N, ret = 0;
	while(l <= r){
		int mid = l+r>>1;
		if(arr[mid].second >= fnd){
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(10);
	int by, xl, xr;
	cin >> by >> xl >> xr;
	cin >> N;
	for(int i = 1; i<=N; i++){
		int l, r;
		cin >> l >> r;
		arr[i] = make_pair(l, r);
		pre[i] = pre[i-1] + r - l;
	}	
	arr[N+1].first = 1100000000;
	int Q;
	cin >> Q;
	while(Q--){
		int x, y;
		cin >> x >> y;
		long double slope = 1.0*(by - y)/(xl - x);
		long double tar = (slope * x - y)/slope;
		if(xl == x){
			tar = x;
		}
		int lft = bs(tar);
		long double out = -pre[lft];
		if(tar <= arr[lft].first){
			out += arr[lft].second - arr[lft].first;
		}
		else{
			//cout << "hi" << "\n";
			out += arr[lft].second - tar;
		}
		//cout << out << " " << tar << "\n";
		//cout << " " << slope << "\n";
		slope = 1.0*(by - y)/(xr - x);
		//cout << " " << slope << "\n";
		tar = (slope * x - y)/slope;
		if(xr == x){
			tar = x;
		}
		int rht = bs(tar);
		if(arr[N].second < tar){
			rht = N+1;
		}
		if(rht == 0){
			cout << 0 << "\n";
		}
		else{
			out += pre[rht-1];
			out += max(0.0, (double) (tar - arr[rht].first));
			//cout << out << "\n";
			cout << max(0.0, (double) ((out*(y - by))/y)) << "\n";
		}
	}
}