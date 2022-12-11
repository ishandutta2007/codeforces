
// Problem : C. Mastermind
// Contest : Codeforces - Codeforces Round #658 (Div. 1)
// URL : https://codeforces.com/contest/1381/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> v[100005];
int fre[100005];
int ans[100005];
int arr[100005];
priority_queue<pair<int, int>> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int testcase = 0; testcase<T; testcase++){
		int N, X, Y;
		cin >> N >> X >> Y;
		for(int i = 1; i<=N+1; i++){
			v[i].clear();
			fre[i] = 0;
			ans[i] = 0;
			arr[i] = 0;
		}
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			arr[i] = n;
			v[n].push_back(i);
			fre[n]++;
		}
		/*
		if(testcase == 37){
			cout << N << " " << X << " " << Y << "\n";
			for(int i = 1; i<=N; i++){
				cout << arr[i] << " ";
			}	
			cout << "\n";
		}
		*/
		int mystery = 0;
		for(int i = 1; i<=N+1; i++){
			if(v[i].empty()){
				mystery = i;
				break;
			}
		}
		for(int i = 1; i<=N+1; i++){
			if(fre[i]){
				pq.push(make_pair(fre[i], i));
			}
		}
		for(int x = 1; x<=X; x++){
			auto p = pq.top();
			int n = p.second;
			pq.pop();
			fre[n]--;
			ans[v[n].back()] = n;
			v[n].pop_back();
			if(fre[n]){
				pq.push(make_pair(fre[n], n));
			}
		}
		bool exist = 1;
		/*
		for(int i = 1; i<=N+1; i++){
			if(fre[i]){
				pq2.push(make_pair(fre[i], i));
			}
		}
		*/
		vector<int> vec;
		int shft = 0;
		while(pq.size()){
			auto p = pq.top();
			shft = max(shft, p.first);
			while(p.first--){
				vec.push_back(p.second);
			}
			pq.pop();
		}
		int cntr = N-Y;
		/*
		for(int x = 1; x<=N-Y; x++){
			auto p = pq.top();
			int n = p.second;
			pq.pop();
			fre[n]--;
			ans[v[n].back()] = mystery;
			v[n].pop_back();
			if(fre[n]){
				pq.push(make_pair(fre[n], n));
			}
			//cout << n << "\n";
		}
		*/
		/*
		while(pq.size()){
			auto p = pq.top();
			pq.pop();
			auto q = pq2.top();
			pq2.pop();
			assert(p.first > 0);
			assert(q.first > 0);
			//cout << " " << p.first << "\n";
			if(p.second != q.second){
				ans[v[p.second].back()] = abs(q.second);
				v[p.second].pop_back();
				q.first--;
				p.first--;
				if(q.first){
					pq2.push(q);
				}
				if(p.first){
					pq.push(p);
				}
			}
			else{
				if(pq2.empty()){
					exist = 0;
					break;
				}
				auto k = pq2.top();
				assert(k.first > 0);
				pq2.pop();
				ans[v[p.second].back()] = abs(k.second);
				v[p.second].pop_back();
				k.first--;
				p.first--;
				if(k.first){
					pq2.push(k);
				}
				if(p.first){
					pq.push(p);
				}
				pq2.push(q);
			}
		}
		*/
		for(int i = 0; i<vec.size(); i++){
			ans[v[vec[i]].back()] = vec[(i+shft)%vec.size()];
			if(ans[v[vec[i]].back()] == arr[v[vec[i]].back()]){
				if(!cntr){
					exist = 0;
				}
				else{
					cntr--;
					ans[v[vec[i]].back()] = mystery;
				}
			}
			else if(vec.size()-i == cntr){
				ans[v[vec[i]].back()] = mystery;
				cntr--;
			}
			v[vec[i]].pop_back();
		}
		if(!exist){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int n = 1; n<=N; n++){
			cout << ans[n] << " ";
			assert(ans[n]);
		}
		cout << "\n";
	}
}