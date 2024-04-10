#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		vector<vector<int> > v;
		v.resize(n);
		for(int i=0;i<n;i++){
			v[i].resize(n);
			v[i][i]=-1;
		}
		vector<int> d;
		for(int i=0;i<n;i++){
			if(s[i]=='2'){
				d.push_back(i);
			}
		}
		if(d.size()==1 || d.size()==2){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		if(d.size()==0){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(v[i][j]==-1){
						cout << "X";
					}
					else if(v[i][j]==0){
						cout << "=";
					}
					else if(v[i][j]==1){
						cout << "+";
					}
					else{
						cout << "-";
					}
				}
				cout << "\n";
			}
			continue;
		}
		for(int i=1;i<d.size();i++){
			v[d[i]][d[i-1]]=1;
			v[d[i-1]][d[i]]=2;
		}
		v[d[0]][d[d.size()-1]]=1;
		v[d[d.size()-1]][d[0]]=2;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i][j]==-1){
					cout << "X";
				}
				else if(v[i][j]==0){
					cout << "=";
				}
				else if(v[i][j]==1){
					cout << "+";
				}
				else{
					cout << "-";
				}
			}
			cout << "\n";
		}
	}
	return 0;
}