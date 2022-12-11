
// Problem : G. Recursive Queries
// Contest : Educational Codeforces Round 60 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1117/G
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[1000005];
int lft[1000005], rht[1000005];
long long ans[1000005];
vector<int> qu[1000005];
long long bit[1000005];

void solve(){
	for(int q = 1; q<=Q; q++){
		qu[rht[q]].emplace_back(q);
	}
	deque<int> stk = {0};
	deque<long long> pre = {0};
	long long tot = 0, instk = 0;
	for(int i = 1; i<=N; i++){
		while(!stk.empty() && arr[stk.front()] < arr[i]){
			int n = stk.front();
			stk.pop_front();
			pre.pop_front();
			int v = i - n - 1;
			instk -= n;
			while(n <= N){
				bit[n] += v;
				n += n&-n;
			}
			tot += v;
		}
		stk.push_front(i);
		pre.push_front(pre.front() + i);
		instk += i;
		for(int n : qu[i]){
			int x = lft[n]-1;
			ans[n] += tot;
			//cout << ans[n] << " " << tot << "\n";
			while(x){
				//cout << "upd: " << bit[x] << "\n";
				ans[n] -= bit[x];
				x -= x&-x;
			}
			int l = 0, r = stk.size()-1, k = 0;
			while(l <= r){
				int mid = l+r>>1;
				if(stk[mid] >= lft[n]){
					l = mid + 1;
					k = mid;
				}
				else{
					r = mid - 1;
				}
			}
			//cout << 1LL*(k+1)*i << " " << (pre.front() - pre[k+1]) << "\n";
			//cout << "bef: " << ans[n] << "\n";
			ans[n] += 1LL*(k+1)*i - pre.front() + pre[k+1];
			//cout << ans[n] << "\n";
		}
		qu[i].clear();
	}
	fill(bit, bit+1+N, 0);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	arr[0] = N+1;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int q = 1; q<=Q; q++){
		cin >> lft[q];
	}
	for(int q = 1; q<=Q; q++){
		cin >> rht[q];
	}
	solve();
	reverse(arr+1, arr+1+N);
	for(int q = 1; q<=Q; q++){
		rht[q] = N - rht[q] + 1;
		lft[q] = N - lft[q] + 1;
		swap(rht[q], lft[q]);
	}
	solve();
	for(int q = 1; q<=Q; q++){
		cout << ans[q] + rht[q] - lft[q] + 1 << " ";
	}
}