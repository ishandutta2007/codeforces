
// Problem : C. Drazil Likes Heap
// Contest : Codeforces Round #631 (Div. 1) - Thanks, Denis aramis Shitov!
// URL : https://codeforces.com/contest/1329/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, H, G;
int arr[1<<22];
vector<int> ans;

int chk(int idx, int dep){
	if(!arr[2*idx] && !arr[2*idx+1]){
		return dep;
	}
	if(arr[2*idx] > arr[2*idx+1]){
		return chk(2*idx, dep+1);
	}
	else{
		return chk(2*idx+1, dep+1);
	}
}

void rem(int idx){
	if(!arr[2*idx] && !arr[2*idx+1]){
		return ;
	}
	if(arr[2*idx] > arr[2*idx+1]){
		swap(arr[idx], arr[2*idx]);
		return rem(2*idx);
	}
	else{
		swap(arr[idx], arr[2*idx+1]);
		return rem(2*idx+1);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> H >> G;
		N = (1<<H);
		N--;
		long long sum = 0;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			sum += arr[i];
		}
		/*
		for(int i = 1; i<=(1<<H)-(1<<G); ){
			if(chk(crnt, crntdep) > G){
				sum -= arr[crnt];
				arr[crnt] = 0;
				rem(crnt);
				ans.emplace_back(crnt);
				i++;
			}
			else{
				crntdep++;
				if(chk(2*crnt, crntdep) > G){
					crnt = 2*crnt;
				}
				else{
					crnt = 2*crnt + 1;
				}
			}
		}
		*/
		int cnt = (1<<H) - (1<<G);
		int crntdep = 1;
		for(int i = 1; i<1<<G; i++){
			if(1<<crntdep == i){
				crntdep++;
			}
			while(cnt && chk(i, crntdep) > G){
				cnt--;
				sum -= arr[i];
				arr[i] = 0;
				rem(i);
				ans.emplace_back(i);
			}
		}
		cout << sum << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		ans.clear();
		fill(arr+1, arr+1+N, 0);
		cout << "\n";
	}
}