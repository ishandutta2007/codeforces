
// Problem : C. Arpa and a game with Mojtaba
// Contest : Codeforces - Codeforces Round #432 (Div. 1, based on IndiaHacks Final Round 2017)
// URL : https://codeforces.com/contest/850/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[105];
map<set<int>, int> mp;

int getgrundy(set<int> s){
	/*
	for(int n : s){
		cout << n << " ";
	}
	cout << endl;
	*/
	if(mp.count(s)){
		return mp[s];
	}
	set<int> st;
	int lim = *(--s.end());
	//cout<< lim << endl;
	for(int i = 1; i<=lim; i++){
		//cout << "i: " << i << endl;
		set<int> temp;
		for(int n : s){
			//cout << n << endl;
			if(n >= i){
				temp.insert(n-i);
			}
			else{
				temp.insert(n);
			}
		}
		//cout << temp.size() << endl;
		//cout << endl;
		//cout << "here" << endl;
		st.insert(getgrundy(temp));
	}
	for(int k = 0; 1; k++){
		if(!st.count(k)){
			return mp[s] = k;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	vector<int> prime;
	for(int i = 1; i<=N; i++){
		int t = arr[i];
		for(int p = 2; p<=sqrt(t); p++){
			if(t%p == 0){
				prime.push_back(p);
				while(t%p == 0){
					t /= p;
				}
			}
		}
		if(t > 1){
			prime.push_back(t);
		}
	}
	mp[{0}] = 0;
	sort(prime.begin(), prime.end());
	prime.erase(unique(prime.begin(), prime.end()), prime.end());
	int x = 0;
	for(int p : prime){
		set<int> st;
		st.insert(0);
		for(int i = 1; i<=N; i++){
			int c = 0;
			while(arr[i]%p == 0){
				arr[i] /= p;
				c++;
			}
			st.insert(c);
		}
		x ^= getgrundy(st);
	}
	if(x){
		cout << "Mojtaba\n";
	}
	else{
		cout << "Arpa\n";
	}
}