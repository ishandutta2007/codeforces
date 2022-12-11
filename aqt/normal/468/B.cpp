
// Problem : B. Two Sets
// Contest : Codeforces - Codeforces Round #268 (Div. 1)
// URL : https://codeforces.com/contest/468/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int arr[100005];
int dsu[200005];
int ans[200005];
map<int, int> mp;
set<int> st, bd;

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

void unite(int a, int b){
	a = getrt(a), b = getrt(b);
	if(a != b){
		dsu[a] = b;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> A >> B;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		dsu[i] = i;
		dsu[i+N] = i+N;
		mp[arr[i]] = i;
	}
	for(int i = 1; i<=N; i++){
		if(!mp.count(A-arr[i]) && !mp.count(B-arr[i])){
			cout << "NO\n";
			return 0;
		}
		else if(!mp.count(B-arr[i])){
			unite(mp[A-arr[i]], i);
			unite(mp[A-arr[i]]+N, i+N);
			ans[i] = 1;
		}
		else if(!mp.count(A-arr[i])){
			unite(mp[B-arr[i]], i);
			unite(mp[B-arr[i]]+N, i+N);
			ans[i] = 2;
		}
		else{
			unite(mp[A-arr[i]], i);
			unite(mp[A-arr[i]]+N, i+N);
			unite(mp[B-arr[i]], i);
			unite(mp[B-arr[i]]+N, i+N);
		}
	}
	for(int i = 1; i<=N; i++){
		if(ans[i] == 1){
			st.insert(getrt(i));
			bd.insert(getrt(i+N));
		}
		else{
			st.insert(getrt(i+N));
			bd.insert(getrt(i));
		}
		if(getrt(i) == getrt(i+N)){
			cout << "NO\n";
			return 0;
		}
	}
	for(int i = 1; i<=N; i++){
		if(st.count(getrt(i))){
			if(ans[i] == 2){
				cout << "NO\n";
				return 0;
			}
			ans[i] = 1;
		}
		else if(st.count(getrt(i+N))){
			if(ans[i] == 1){
				cout << "NO\n";
				return 0;
			}
			ans[i] = 2;
		}
		else if(!bd.count(getrt(i))){
			st.insert(getrt(i));
			bd.insert(getrt(i+N));
			ans[i] = 1;
		}
		else{
			st.insert(getrt(i+N));
			bd.insert(getrt(i));
			ans[i] = 2;
		}
	}
	cout << "YES\n";
	for(int i = 1; i<=N; i++){
		cout << ans[i]-1 << " ";
	}
}