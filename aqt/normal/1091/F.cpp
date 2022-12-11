
// Problem : F. New Year and the Mallard Expedition
// Contest : Good Bye 2018
// URL : https://codeforces.com/problemset/problem/1091/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[100005];
vector<pair<long long, int>> v;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long lft = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		lft += arr[i];
	}
	bool hasseenW = 0;
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		pair<long long, int> p = {arr[i], 0};
		if(c == 'W'){
			hasseenW = 1;
			p.second = 3;
		}
		else if(c == 'L'){
			p.second = 1;
		}
		else{
			p.second = 5;
		}
		if(v.size() && v.back().second == p.second){
			p.first += v.back().first;
			v.pop_back();
		}
		v.push_back(p);
	}
	long long tot = 0;
	hasseenW = 0;
	long long ans = 0;
	long long extrag = 0;
	for(auto p : v){
		if(p.second == 3){
			hasseenW = 1;
		}	
		if(p.second == 1){
			if(tot >= p.first){
				tot -= p.first;
			}
			else if(hasseenW){
				ans += 3*(p.first - tot);
				tot = 0;
			}
			else{
				ans += 5*(p.first - tot);
				tot = 0;
			}
			ans += p.first*p.second;
		}
		else {
			/*
			if(lft - p.first <= tot + p.first){
				if((lft - tot)%2 == 0){
					long long k = (lft - tot)/2;
					ans += k*p.second;
					ans += lft-k;
				} 
				else{ 
					//long long k = (lft - tot)/2;
					//cout << lft-tot << endl;
					//ans += k*p.second;
					//ans += lft - k - 1;	
					ans += (p.second+1)/2*(lft-tot);
				}
				break;
			}
			else{
				tot += p.first;
				ans += p.first*p.second;
			}
			*/
			tot += p.first;
			ans += p.first*p.second;
			if(p.second == 5){
				extrag += 2*p.first;
			}
		}
		extrag = min(extrag, tot);
		lft -= p.first;
	}
	ans -= extrag + tot;
	cout << ans << "\n";
}