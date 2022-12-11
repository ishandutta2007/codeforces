// Problem : D. Picking Strings
// Contest : Codeforces - VK Cup 2018 - Round 1
// URL : https://codeforces.com/problemset/problem/923/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int pre[2][100005];

int bs(int k, int n){
	int l = 1, r = 100000, ret = -1;
	while(l <= r){
		int mid = l+r>>1;
		if(pre[k][mid] >= n){
			r = mid - 1;
		}
		else{
			l = mid + 1;
			ret = mid;
		}
	}
	ret++;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int k = 0; k<2; k++){
		string s;
		cin >> s;
		for(int n = 1; n<=s.size(); n++){
			if(s[n-1] != 'A'){
				pre[k][n]++;
			}
			//pre[k][n] += pre[k][n-1];
		}
		partial_sum(pre[k], pre[k]+100001, pre[k]);
	}
	int Q;
	cin >> Q;
	while(Q--){
		int l1, r1, l0, r0;
		cin >> l0 >> r0 >> l1 >> r1;
		int f0 = pre[0][r0] - pre[0][l0-1];
		int f1 = pre[1][r1] - pre[1][l1-1];
		bool cond1 = f1 >= f0 && (f1%2 == f0%2);
		int z0 = max(l0-1, (int) (lower_bound(pre[0], pre[0]+100001, pre[0][r0])-pre[0]));
		int z1 = max(l1-1, (int) (lower_bound(pre[1], pre[1]+100001, pre[1][r1])-pre[1]));
		//cout << z0 << " " << z1 << "\n";
		z0 = r0 - z0;
		z1 = r1 - z1;
		//cout << z0 << " " << z1 << "\n";
		//bool cond2 = (z0 >= z1 && (z1 == 0 && f1 > f0) || (z1%3 == z0%3 && z0 >= z1));
		//cout << (((z1 == 0 && f1 > f0) || (z1%3 == z0%3 && z0 >= z1)) && f1 >= f0 && ((f1-z1)%2 == (f0-z0)%2));
		//cout << z1 << " " << z0 << " " << ((z0-z1)%3*2+f0 <= f1) << "\n";
		bool cond2 = (z0 >= z1 && ((z0-z1)%3!=0)*2+f0 <= f1) && (z0 != z1 || !!f1 == !!f0);
		if(cond1 && cond2){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
}