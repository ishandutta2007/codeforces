
// Problem : C. Fixed Point Removal
// Contest : Codeforces - Codeforces Round #668 (Div. 1)
// URL : https://codeforces.com/contest/1404/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[300005];
int lft[300005], rht[300005];
int bit[300005];
int ans[300005];
int k[300005];
vector<int> qu[300005];
vector<int> up[300005];

void upd(int n ,int v){
	while(n <= N){
		bit[n] += v;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

int clmb(int v){
	int idx = 0;
	int tot = 0;
	for(int d = 20; d>=0; d--){
		if((1<<d)+idx <= N && tot + bit[(1<<d)+idx] < v){
			idx += (1<<d);
			tot += bit[idx];
		}
	}
	return idx+1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int q = 1; q<=Q; q++){
		cin >> lft[q] >> rht[q];
		lft[q]++;
		rht[q] = N - rht[q];
		qu[lft[q]].push_back(q);
	}
	int bad = 0;
	for(int i =1 ; i<=N; i++){
		if(arr[i] > i){
			k[i] = N+1;
			bad++;
		}
		else{
			/*
			if(arr[i]-1-bad < 0){
				k[i] = N+1;
			}
			else{
				k[i] = clmb(arr[i]-1-bad);
			}
			*/
			int l = 0, r = i-1;
			int d = i - arr[i];
			int tot = query(i);
			if(tot < d){
				k[i] = N+1;
			}
			else{
				while(l <= r){
					int mid = l+r>>1;
					if(tot - query(mid) >= d){
						k[i] = mid+1;
						l = mid + 1;
					}	
					else{
						r = mid - 1;
					}
				}
			}
			
		}
		upd(k[i], 1);
		up[k[i]].push_back(i);
		//cout << i << " " << k[i] << "\n";
	}
	fill(bit, bit+2+N, 0);
	for(int n = N; n; n--){
		for(int p : up[n]){
			upd(p, 1);
		}
		for(int q : qu[n]){
			ans[q] = query(rht[q]);
		}
	}
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << "\n";
	}
}