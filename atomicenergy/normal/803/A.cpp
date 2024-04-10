#include <iostream>
using namespace std;

bool G[100][100];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			G[i][j] = false;
			G[j][i] = false;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(i==j && m>0){
				G[i][j] = true;
				G[j][i] = true;
				m--;
			}
			if(i!=j && m>1){
				G[i][j] = true;
				G[j][i] = true;
				m-=2;
			}
		}
	}
	if(m==0){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << G[i][j] << " ";
			}
			cout << endl;
		}
	}else{
		
		cout << -1 << endl;
	}
	return 0;
}