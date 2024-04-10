#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;
//mod p^n, how many ps;


int main() {
	int n;
	vector<set<int> > v;
	cin >> n;
	set<int> p;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		set<int> u;	
		for(int j=2; j*j<=x; j++){
			if(x%j==0) {
				u.insert(j);
				p.insert(j);
			}
			while(x%j==0) x/=j;
		}
		if(x>1){
			u.insert(x);
			p.insert(x);
		}
		v.push_back(u);
	}
	vector<vector<int>> dp;
	for(int i=0; i<n; i++){
		vector<int> u;
		for(int j : p){
			if(i==0){
				if(!v[i].count(j)){
					u.push_back(0);
				}
				else{
					u.push_back(-1);
				}
			}else{
				if(!v[i].count(j)){
					u.push_back(0);
				}
				else{
					int z = dp[dp.size()-1][u.size()];
					if(z>=0) z++;
					u.push_back(z);
				}
			}
		}
		dp.push_back(u);
	}
	
	int min = -1;
	int tot1s = 0;
	for(int i=0; i<n; i++){
		int tot = 0;
		int mx = 0;
		for(int j = 0; j<dp[i].size(); j++){
			//cout << i << " " << j << " " << dp[i][j] << endl;
			int z = dp[i][j];
			if(z==-1) mx = -1;
			else{
				if(mx != -1 && z > mx){
					mx = z;
				}
			}
			//cout << i << " " << j << " " << mx << endl;
		}
		tot = mx;
		
		if(tot==0){
			tot1s++;
		}
		if(min==-1 || min > tot){
			min = tot;
		}
	}
	if(min == -1){
		cout << -1 << endl;
	}
	
	else if(min == 0){
		cout << n - tot1s << endl;
	}	
	else{
		cout << n + min - 1 << endl;
	}
}