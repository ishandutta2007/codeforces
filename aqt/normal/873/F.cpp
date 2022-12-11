
// Problem : F. Forbidden Indices
// Contest : Educational Codeforces Round 30
// URL : https://codeforces.com/contest/873/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<char> v;
vector<int> bad;
int sa[200005];
pair<pair<int, int>, int> srt[200005];
int pos[200005];
int lcp[200005];
int pre[200005];
int arr[200005];
stack<pair<int, int>> stk;

void getpos(){
	sort(srt, srt+N);
	int idx = 0;
	for(int j = 0; j<N; j++){
		if(j && srt[j-1].first != srt[j].first){
			idx++;
		}
		pos[srt[j].second] = idx;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long ans = 0;
	for(int i = 0; i<N; i++){
		char c;
		cin >> c;
		v.emplace_back(c);
	}
	for(int i = 0; i<N; i++){
		char c;
		cin >> c;
		int k = c-'0';
		bad.emplace_back(k);
		if(!k){
			ans = max(ans, 1LL*(i+1));
		}
	}
	reverse(v.begin(), v.end());
	reverse(bad.begin(), bad.end());
	v.emplace_back('$');
	N++;
	for(int i = 0; i<N-1; i++){
		srt[i] = {{v[i]-'a'+1, 0}, i};
	}
	srt[N-1] = {{0, 0}, N-1};
	getpos();
	for(int k = 1; k<20; k++){
		for(int i = 0; i<N; i++){
			srt[i] = {{pos[i], pos[(i+(1<<(k-1)))%N]}, i};
		}
		getpos();
	}
	for(int i = 1; i<N; i++){
		sa[i] = srt[i].second;
		pre[i] = !bad[sa[i]];
		pre[i] += pre[i-1];
	}
	int d = 0;
	for(int i = 0; i<N-1; i++){
		if(pos[i] == N-1){
			d = 0;
			continue;
		}
		d -= !!d;
		int j = sa[pos[i]+1];
		while(v[i+d] == v[j+d]){
			d++;
		}			
		lcp[pos[i]] = d;
	}
	stk.push({0, 0});
	for(int i = 1; i<N-1; i++){
		while(stk.size() > 1 && stk.top().first >= lcp[i]){
			long long h = stk.top().first;
			stk.pop();
			//cout << (pre[i]-pre[stk.top().second]) << "\n";
			ans = max(ans, h*(pre[i]-pre[stk.top().second]));
		}
		stk.push({lcp[i], i});
	}
	while(stk.size() > 1){
		long long h = stk.top().first;
		stk.pop();
		ans = max(ans, h*(pre[N-1]-pre[stk.top().second]));
	}
	cout << ans << "\n";
}