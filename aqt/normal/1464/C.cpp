
// Problem : C. Poman Numbers
// Contest : Codeforces - Codeforces Round #692 (Div. 1, based on Technocup 2021 Elimination Round 3)
// URL : https://codeforces.com/contest/1464/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

/*
string s;

set<string> rec(int n){
	if(n == 1){
		set<string> st;
		st.insert("+");
		return st;
	}
	set<string> st;
	for(int m = 1; m<n; m++){
		auto lft = rec(m);
		auto rht = rec(n-m);
		for(auto l : lft){
			string s = l;
			for(int i = 0; i<s.size(); i++){
				if(s[i] == '+'){
					s[i] = '-';
				}
				else{
					s[i] = '+';
				}
			}
			for(auto r : rht){
				st.insert(s+r);
			}
		}
	}
	return st;
}
*/

int N;
long long K;
int arr[100005];
long long fre[50];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	/*
	for(int n = 1; n<=6; n++){
		cout << "test: " << n << "\n";
		auto st = rec(n);
		for(auto s : st){
			cout << s << "\n";
		}
	}
	*/
	for(int i =1; i<=N; i++){
		char c;
		cin >> c;
		arr[i] = c-'a';
	}
	K -= (1<<arr[N]) - (1<<arr[N-1]);
	long long tot = 0;
	for(int i = 1; i<=N-2; i++){
		fre[arr[i]]++;
		tot += (1<<arr[i]);
	}
	/*
	int init = 0;	
	for(int k = 0; k<25; k++){
		if(fre[k]/2 && fre[k]/2 > 1){
			init |= (1<<(k+1));
		}
		fre[k+1] += fre[k]/2;
		fre[k] %= 2; 
		init |= (1<<k)*fre[k];
	}
	for(int msk = init; 1; msk = (init & (msk-1))){
		long long val = msk - (init^msk);
		long long temp = (K - val)/(1LL<<25);
		if((K-val)%(1LL<<25) == 0 && abs(temp) <= fre[25] && fre[25]%2 == abs(temp)%2){
			cout << "Yes\n";
			return 0;
		}
		if(msk == 0){
			break;
		}
	}
	cout << "No\n";
	*/
	sort(arr+1, arr+1+N-2, greater<int>());
	K = tot - K;
	for(int i = 1; i<=N-2; i++){
		arr[i]++;
		if(K-(1<<arr[i]) >= 0){
			K -= (1<<arr[i]);
		}
	}
	if(!K){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
}