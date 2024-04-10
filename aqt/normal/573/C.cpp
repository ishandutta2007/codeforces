
// Problem : C. Bear and Drawing
// Contest : Codeforces - Codeforces Round #318 [RussianCodeCup Thanks-Round] (Div. 1)
// URL : https://codeforces.com/contest/573/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
set<int> graph[100005];
bool leaf[100005];
int cnt[100005];
bool sp[100005];
bool ans = 1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	queue<int> qu;
	for(int i = 1; i<=N; i++){
		if(graph[i].size() <= 1){
			leaf[i] = 1;
			sp[i] = 1;
			if(graph[i].size() == 1){
				qu.push(i);
			}
		}
	}
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		while(1){
			int i = *(graph[n].begin());
			if(graph[i].size() == 2){
				int a = *(graph[i].begin()), b = *(++graph[i].begin());
				graph[a].erase(i);
				graph[b].erase(i);
				graph[a].insert(b);
				graph[b].insert(a);
				graph[i].clear();
			}
			else{
				break;
			}
		}
	}
	for(int i = 1; i<=N; i++){
		if(graph[i].size()){
			for(int e : graph[i]){
				cnt[i] += leaf[e];
			}
			sp[i] |= (cnt[i] == 2 && graph[i].size() == 3);
		}
	}
	for(int i = 1; i<=N; i++){
		if(graph[i].size()){
			int c = 0;
			for(int e : graph[i]){
				if(!sp[e]){
					c++;
				}
			}
			//cout << i << " " << cnt << "\n";
			if(c > 2){
				ans = 0;
			}
		}
	}
	cout << (ans ? "Yes" : "No");
}