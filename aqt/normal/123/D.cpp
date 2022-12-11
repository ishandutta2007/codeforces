
// Problem : D. String
// Contest : Codeforces - Codeforces Beta Round #92 (Div. 1 Only)
// URL : https://codeforces.com/contest/123/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int sa[100005];
int ord[100005];
pair<pair<int, int>, int> srt[100005];
int lcp[100005];
pair<int, int> lcpsrt[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	s.push_back('$');
	N = s.size();	
	for(int i = 0; i<N; i++){
		srt[i].first.first = s[i];
		srt[i].second = i;
	}
	sort(srt, srt+N);
	int idx = 0;
	for(int i= 0; i<N; i++){
		if(i && srt[i].first != srt[i-1].first){
			idx++;
		}
		sa[i] = srt[i].second;
		ord[srt[i].second] = idx;
	}
	for(int d = 0; d<20; d++){
		for(int i = 0; i<N; i++){
			srt[i].first.first = ord[i];
			srt[i].first.second = ord[(i+(1<<d))%N];
			srt[i].second = i;
		}
		sort(srt, srt+N);
		idx = 0;
		for(int i = 0; i<N; i++){
			if(i && srt[i].first != srt[i-1].first){
				idx++;
			}
			sa[i] = srt[i].second;
			ord[srt[i].second] = idx;
		}
		/*
		cout << "Iteration: " << d << "\n";
		for(int i =0 ; i<N; i++){
			cout << sa[i] << "\n";
			cout << srt[i].first.first << " " << srt[i].first.second << "\n";
		}
		*/
	}
	int d = 0;
	for(int i = 0; i<N; i++){
		if(ord[i] == N-1){
			d = 0;
			continue;
		}
		d = max(0, d-1);
		int j = sa[ord[i] + 1];
		while(s[i+d] == s[j+d]){
			d++;
		}
		lcp[ord[i]] = d;
	}
	/*
	for(int i =0; i<N; i++){
		cout << sa[i] << "\n";
	}
	cout << "\n";
	*/
	/*
	for(int i = 0; i<N; i++){
		cout << ord[i] << "\n";
	}
	*/
	/*
	for(int i = 0; i<N; i++){
		cout << lcp[i] << "\n";
	}
	*/
	vector<pair<int, int>> stk = {make_pair(-1, 0)};
	long long ans = 0;	
	for(int i = 0; i<N; i++){
		while(stk.back().second > lcp[i]){
			auto p = stk.back();
			stk.pop_back();
			long long n = (i - stk.back().first);
			n = n*(n+1)/2;
			//cout << " " << n << "\n";
			//cout << " " << i << " " << p.second - max(stk.back().second, lcp[i]) << "\n";
			ans += 1LL* n * (p.second - max(stk.back().second, lcp[i]));
		}
		stk.emplace_back(i, lcp[i]);
	}
	//cout << ans << "\n";
	for(int i = 0; i<N; i++){
		int mx = lcp[i];
		if(i){
			mx = max(lcp[i-1], mx);
		}
		ans += N - sa[i] - mx - 1;
	}
	cout << ans << "\n";
}