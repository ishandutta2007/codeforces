#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long a, b, k;
		cin >> a >> b >> k;
		vector<long long> ans;
		if(a == b){
			ans.push_back(a);
		}
		else{
			vector<long long> coe(55);
			long long lb = a+1, ub = a+k;
			int len = 1;
			while(ub < b){
				//cout << lb << " " << ub << "\n";
				lb = 2 * (lb);
				ub = 2 * (ub);
				len++;
			}
			if(lb <= b){
				b--;
				for(long long i = 0; i<len-1; i++){
					b -= (1LL << i);
				}
				b -= (a << (len-1));
				for(int i = 0; i<len-1; i++){
					coe[i] = (b>>(len-2-i));
					coe[i] = min(coe[i], k-1);
					b -= (coe[i]<<(len-2-i));
				}
				coe[len-1] = b;
				ans.push_back(a);
				for(int i = 0; i<len; i++){
					long long tot = 0;
					for(long long n : ans){
						tot += n;
					}
					tot += coe[i] + 1;
					ans.push_back(tot);
				}
			}
		}
		if(ans.size() == 0){
			cout << -1 << "\n";
		}
		else{
			cout << ans.size() << " ";
			for(long long n : ans){
				cout << n << " ";
			}
			cout << "\n";
		}
	}
}