#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	vector<int> b(m+1);
	vector<vector<int> > v(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin >> c;
			if(c=='X'){
				v[i][j]=1;
			}
			if(v[i][j-1]==1 && v[i-1][j]==1){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		b[i]+=b[i-1];
	}
	int q;
	cin >> q;
	int a,c;
	for(int i=0;i<q;i++){
		cin >> a >> c;
		if(b[c]-b[a]==0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}