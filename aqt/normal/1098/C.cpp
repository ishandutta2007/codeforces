
// Problem : C. Construct a tree
// Contest : Codeforces - Codeforces Round #530 (Div. 1)
// URL : https://codeforces.com/contest/1098/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long S;
int qu[1000005];
int dep[1000005];
int hasdep[1000005];

vector<int> solve(int k){
	vector<int> ret(N+5);
	dep[1] = 1;
	fill(hasdep+1, hasdep+1+N, 0);
	qu[1] = 1;
	int l = 1, r = 1;
	long long nxt = 1;
	dep[1] = 1;
	long long tot = 0;
	int mxdep = 0;
	while(l <= r){
		int n = qu[l++];
		if(!hasdep[dep[n]]){
			hasdep[dep[n]] = n;
		}
		mxdep = max(mxdep, dep[n]);
		tot += dep[n];
		for(int i = 1; i <= k && nxt <= N; i++){
			if(i + nxt <= N){
				qu[++r] = (i + nxt);
				dep[i + nxt] = dep[n] + 1;
				ret[i + nxt] = n; 
				//cout << i + n << " " << n << endl;
			}
		}
		nxt += k;
	}
	//cout << endl;
	if(tot > S){
		return {};
	}
	for(int i = N; i && tot != S; i--){
		//cout << i << " " << tot << endl;
		if(hasdep[dep[i]] != i){
			if(tot + mxdep - dep[i] >= S){
				int p = hasdep[S - tot + dep[i] - 1];
				ret[i] = p;
				tot = S;
			}
			else{
				ret[i] = hasdep[mxdep];
				hasdep[mxdep+1] = i;
				tot += mxdep - dep[i] + 1;
				dep[i] = mxdep + 1;
				//cout << " "<<  i << " " << tot << endl;
				mxdep++;
			}
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	if(S < 2 * N - 1 || S > 1LL * N * (N + 1) / 2){
		cout << "No\n";
		return 0;
	}
	int l = 1, r = N;
	vector<int> ans;
	while(l <= r){
		int mid = l + r >> 1;
		vector<int> tmp = solve(mid);
		if(tmp.size()){
			ans = tmp;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << "Yes\n";
	for(int k = 2; k <= N; k++){
		cout << ans[k] << " "; 	
	}
}