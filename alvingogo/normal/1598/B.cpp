#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int> > v(n,vector<int>(5));
		vector<int> a,b,c;
		for(int i=0;i<n;i++){
			for(int j=0;j<5;j++){
				cin >> v[i][j];
			}
		}
		if(n%2){
			cout << "NO\n";
			continue;
		}
		int flag=0;
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				a.clear();
				b.clear();
				c.clear();
				for(int k=0;k<n;k++){
					if(v[k][i]==1 && v[k][j]==1){
						c.push_back(k);
					}
					else if(v[k][i]==1){
						b.push_back(k);
					}
					else if(v[k][j]==1){
						a.push_back(k);
					}
				}
				if(a.size()<=n/2 && b.size()<=n/2 && a.size()+b.size()+c.size()==n){
					flag=1;
				}
			}
		}
		if(flag){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
		
	return 0;
}