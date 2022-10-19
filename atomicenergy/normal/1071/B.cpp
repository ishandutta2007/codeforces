#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<char> > v(n, vector<char>(n));
	vector<vector<int> > num(n, vector<int>(n));
	vector<vector<bool> > pre(n, vector<bool> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
	bool phase1 = true;
	string ans;
	int j;
	for(int s=0; s<2*n-1; s++){
		bool nonefound = true;
		if(phase1){
			for(int i=0; i<n; i++){
				j = s-i;
				if(j<0 || j>=n) continue;
				if(i==0 && j==0){
					if(v[i][j] == 'a') num[i][j] = 0;
					else num[i][j] = 1;
				}
				else if(j==0){
					if(v[i][j] == 'a') num[i][j] = num[i-1][j];
					else num[i][j] = num[i-1][j] + 1;
					pre[i][j] = true;
				}
				else if(i==0){
					if(v[i][j] == 'a') num[i][j] = num[i][j-1];
					else num[i][j] = num[i][j-1] + 1;
					pre[i][j] = false;
				}
				else{
					pre[i][j] = false;
					if(v[i][j] == 'a'){
						num[i][j] = min(num[i-1][j], num[i][j-1]);
						if(num[i][j] <= k && num[i-1][j] < num[i][j-1]){
							pre[i][j] = true;
						}
					}else{
						num[i][j] = min(num[i-1][j], num[i][j-1]) + 1;
						if(num[i][j] <= k && num[i-1][j] < num[i][j-1]){
							pre[i][j] = true;
						}
					}
					
				}
				if(num[i][j] <= k) nonefound = false;
			}
		}
		if(nonefound && phase1){
			for(int i=0; i<s; i++){
				ans+='a';
			}
			phase1 = false;
		}
		if(phase1){
			for(int i=0; i<n; i++){
				j = s-i;
				if(j < 0 || j>=n) continue;
				if(num[i][j] <= k) v[i][j] = 'a';
				else v[i][j] = 'z' + 1;
			}
		}
		if(!phase1){
			char mn = 'z' + 1;
			//cout << s << endl;
			for(int i=0; i<n; i++){
				j = s-i;
				if(j < 0 || j>=n) continue;
				if((i==0 && j==0)
				|| (i==0 && j>0 && v[i][j-1] <= 'z')
				|| (j==0 && i>0 && v[i-1][j] <= 'z')
				|| (i>0 && j>0 && (v[i-1][j] <= 'z'
				|| v[i][j-1] <= 'z'))){
					//cout << "here" << v[i][j] << i << j << endl;
					mn = min(v[i][j], mn);
				}
			}
			//cout << mn << endl;
			ans+=mn;
			for(int i=0; i<n; i++){
				j = s-i;
				if(j < 0 || j>=n) continue;
				if(!((i==0 && j==0)
				|| (i==0 && j>0 && v[i][j-1] <= 'z')
				|| (j==0 && i>0 && v[i-1][j] <= 'z')
				|| (i>0 && j>0 && (v[i-1][j] <= 'z'
				|| v[i][j-1] <= 'z')))){
					//cout << "here" << v[i][j] << i << j << endl;
					v[i][j] = 'z'+1;
				}
				if(v[i][j] != mn) v[i][j] = 'z'+1;
			}
		}
		
	}
	if(phase1){
				for(int i=0; i<2*n-1; i++){
				ans+='a';
			}
			phase1 = false;
		}
	cout << ans << endl;
	return 0;
}