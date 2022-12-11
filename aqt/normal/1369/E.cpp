
// Problem : E. DeadLee
// Contest : Codeforces - Codeforces Round #652 (Div. 2)
// URL : https://codeforces.com/contest/1369/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[200005], b[200005];
int arr[200005];
int cnt[200005];
vector<int> v[200005];
int ans[200005];
bool tkn[200005];
bool comp[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=M; i++){
		cin >> a[i] >> b[i];
		v[a[i]].push_back(i);
		v[b[i]].push_back(i);
		cnt[a[i]]++;
		cnt[b[i]]++;
	}
	int idx = M;
	queue<int> qu;
	for(int i = 1; i<=N; i++){
		if(arr[i] >= cnt[i]){
			comp[i] = 1;
			qu.push(i);
		}
	}
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int k : v[n]){
			if(!tkn[k]){
				tkn[k] = 1;
				if(!comp[a[k]]){
					cnt[a[k]]--;
					if(arr[a[k]] >= cnt[a[k]]){
						comp[a[k]] = 1;
						qu.push(a[k]);
					}
				}
				if(!comp[b[k]]){
					cnt[b[k]]--;
					if(arr[b[k]] >=cnt[b[k]]){
						comp[b[k]] = 1;
						qu.push(b[k]);
					}
				}
				ans[idx--] = k;
			}
		}
	}
	for(int n = 1; n<=N; n++){
		if(!comp[n]){
			cout << "DEAD\n";
			return 0;
		}
	}
	cout << "ALIVE\n";
	for(int i = 1; i<=M; i++){
		cout << ans[i] << " ";
	}
}