
// Problem : F. New Year and Cleaning
// Contest : Codeforces - Good Bye 2015
// URL : https://codeforces.com/contest/611/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, H, W;
string s;
vector<long long> ver, hor;
vector<long long> pver, phor;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> W >> H >> s;
	int vr = 0, vl = 0, cv = 0;
	int hr = 0, hl = 0, ch = 0;
	for(int i = 1; i<=N; i++){
		if(s[i-1] == 'U'){
			cv++;
			if(vr < cv){
				vr = cv;
				ver.push_back(i);
			}
		}
		else if(s[i-1] == 'D'){
			cv--;
			if(vl > cv){
				vl = cv;
				ver.push_back(i);
			}
		}
		else if(s[i-1] == 'L'){
			ch--;
			if(hl > ch){
				hl = ch;
				hor.push_back(i);
			}
		}
		else{
			ch++;
			if(hr < ch){
				hr = ch;
				hor.push_back(i);
			}
		}
	}
	for(int i = 1; i<=N; i++){
		if(s[i-1] == 'U'){
			cv++;
			if(vr < cv){
				vr = cv;
				pver.push_back(i);
			}
		}
		else if(s[i-1] == 'D'){
			cv--;
			if(vl > cv){
				vl = cv;
				pver.push_back(i);
			}
		}
		else if(s[i-1] == 'L'){
			ch--;
			if(hl > ch){
				hl = ch;
				phor.push_back(i);
			}
		}
		else{
			ch++;
			if(hr < ch){
				hr = ch;
				phor.push_back(i);
			}
		}
	}
	if(phor.size()){
		for(int c = 1; hor.size() < H; c++){
			for(int n = 0; n<phor.size() && hor.size() < H; n++){
				hor.push_back(1LL * c * N + phor[n]);
			}
		}
	}
	if(pver.size()){
		for(int c = 1; ver.size() < W; c++){
			for(int n = 0; n<pver.size() && ver.size() < W; n++){
				ver.push_back(1LL * c * N + pver[n]);
			}
		}
	}
	if(hor.size() < H && ver.size() < W){
		cout << -1 << "\n";
		return 0;
	}
	hor.push_back(LLONG_MAX/2);
	ver.push_back(LLONG_MAX/2);
	int idxh = 0, idxv = 0;
	long long ans = 0;
	while(idxh < H && idxv < W){
		if(hor[idxh] < ver[idxv]){
			ans += (W-idxv)*hor[idxh];
			idxh++;
		}
		else{
			ans += (H-idxh)*ver[idxv];
			idxv++;
		}
		ans %= 1000000007;
	}
	cout << ans;
}