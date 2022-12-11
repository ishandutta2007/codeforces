
// Problem : F. Maximum Reduction
// Contest : Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1037/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long ans = 0;
int arr[1000005];
pair<int, int> srt[1000005];
set<int> st;

/*
long long sum(long long l, long long r){
	return (l+r)*((r-l)/(K-1)+1)/2;
}
*/

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		ans -= arr[i];
		srt[i] = {arr[i], i};
	}
	sort(srt+1, srt+1+N, greater<pair<int, int>>());
	st.insert(0), st.insert(N+1);
	for(int i = 1; i<=N; i++){
		auto it = st.lower_bound(srt[i].second);
		int r = *it, l = *(--it);
		r--, l++;
		int p = srt[i].second, v = srt[i].first;
		int mn = min(r-p, p-l), mx = max(r-p, p-l);
		mn++, mx++;
		long long l1 = (mn-1)/(K-1);
		long long cnt = (2+l1*(K-1))*(l1+1)/2;
		//ans += (2+l1*(K-1))*(l1+1)/2*v;
		//cout << v << " " << l1 << " " << cnt << "\n";
		//cout << ans << "\n";
		long long l2 = (mx-1)/(K-1);
		//ans += ((l1+1)*(K-1)+(l2+1)*(K-1)+2)*(l2-l1)/2*v*(mn);	
		cnt += (l2-l1)*(mn);
		//cout << v << " " << l2 << " " << cnt << "\n";
		//ans += (l2-l1)*(mn)*v;
		//cout << ans << "\n";
		long long l3 = (r-l)/(K-1);
		//cout << v << " " << l3 << "\n";
		if(l2 != l3){
			long long k = (r-l+1)-(l3)*(K-1);
			cnt += (2*k+(l3-l2-1)*(K-1))*(l3-l2)/2;
			//ans += (2*k+(l3-l2-1)*(K-1))/2*v;
			//cout << v << " " << l3 << " " << cnt << " " << k << "\n";
		}
		ans += cnt%1000000007*v;
		//cout << ans << "\n";
		//cout << cnt << "\n";
		ans %= 1000000007;
		st.insert(p);
	}
	cout << ans << "\n";
}