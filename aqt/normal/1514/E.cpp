
// Problem : E. Baby Ehab's Hyper Apartment
// Contest : Codeforces - Codeforces Round #716 (Div. 2)
// URL : https://codeforces.com/contest/1514/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[105];
int ans[105][105];
int eq[105];

void mergesort(int l, int r){
	if(l == r){
		return;
	}
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);
	vector<int> lft, rht;
	for(int i = l; i<=mid; i++){
		lft.push_back(arr[i]);
	}
	for(int i =mid+1; i<=r; i++){
		rht.push_back(arr[i]);
	}
	int idx1 = 0, idx2 = 0;
	while(idx1 < lft.size() && idx2 < rht.size()){
		cout << 1 << " " << lft[idx1] << " " << rht[idx2] << endl;
		int q;
		cin >> q;
		assert(q != -1);
		if(q){
			arr[l+idx1+idx2] = lft[idx1];
			idx1++;
		}
		else{
			arr[l+idx1+idx2] = rht[idx2];
			idx2++;
		}
	}
	while(idx1 < lft.size()){
		arr[l+idx1+idx2] = lft[idx1];
		idx1++;
	}
	while(idx2 < rht.size()){
		arr[l+idx1+idx2] = rht[idx2];
		idx2++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		iota(arr, arr+N, 0);
		fill(eq, eq+N, 0);
		mergesort(0, N-1);
		for(int r = N-1, l = N-2; r>=0; r--){
			if(r == l){
				l--;
			}
			while(l >= 0){
				cout << 2 << " " << arr[r] << " " << l+1 << " ";
				for(int i = 0; i<=l; i++){
					cout << arr[i] << " ";
				}
				cout << endl;
				int q;
				cin >> q;
				assert(q != -1);
				if(q){
					eq[l] = 1;
					l--;
				}
				else{
					break;
				}
			}
		}
		for(int i = 0; i<N; i++){
			fill(ans[arr[i]], ans[arr[i]]+N, 0);
			for(int j = i; j<N; j++){
				ans[arr[i]][arr[j]] = 1;
			}
			for(int j = i-1; j >= 0 && eq[j]; j--){
				ans[arr[i]][arr[j]] = 1;
			}
		}
		cout << 3 << "\n";
		for(int i= 0; i<N; i++){
			for(int j = 0; j<N; j++){
				cout << ans[i][j];
			}
			cout << "\n";
		}
		cout.flush();
		int res;
		cin >> res;
		assert(res != -1);
	}
}