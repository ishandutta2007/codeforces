#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
int a[300300];
int pos[300300];
int diff[300300];
int cntdiff[300300];
bool used[300300];
bool check(int k){
	rep(i, n)
		used[i] = 0;
	int cnt = 0, cntcc = 0;
	rep(i, n){
		int reali = (i + n - k) % n;
		if(reali != a[i]){
			cnt++;
			if(!used[reali]){
				cntcc++;
				int nowpos = reali;
				do{
					used[nowpos] = 1;
					nowpos = a[(nowpos + k) % n];
				}while(nowpos != reali);
			}
		}
	}
	return (cnt - cntcc <= m);
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n){
			cin >> a[i];
			a[i]--;
			pos[a[i]] = i;
		}
		rep(i, n)
			cntdiff[i] = 0;
		rep(i, n){
			diff[i] = (pos[i] + n - i) % n;
			cntdiff[diff[i]]++;
		}
		vector<int> ans;
		rep(i, n){
			if(cntdiff[i] >= n - m * 2){
				if(check(i))
					ans.push_back(i);
			}
		}
		cout << ans.size() << " ";
		rep(i, (int)ans.size())
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}