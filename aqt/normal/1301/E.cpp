
// Problem : E. Nanosoft
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/E
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int arr[505][505];
int pre[5][505][505];
int sz[505][505];
int ans[300005];
int bx[300005], by[300005], tx[300005], ty[300005];

int sum(int t, int x1, int x2, int y1, int y2){
	return pre[t][x2][y2] - pre[t][x2][y1] - pre[t][x1][y2] + pre[t][x1][y1];
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			char c;
			cin >> c;
			arr[i][j] += (c == 'G' ? 1 : 0);
			arr[i][j] += (c == 'R' ? 2 : 0);
			arr[i][j] += (c == 'Y' ? 3 : 0);
			arr[i][j] += (c == 'B' ? 4 : 0);
			pre[arr[i][j]][i][j]++;
			for(int k =1 ; k<=4; k++){
				pre[k][i][j] += pre[k][i-1][j] + pre[k][i][j-1] - pre[k][i-1][j-1];
			}
		}
	}
	for(int i = 1; i<N; i++){
		for(int j =1 ; j<M; j++){
			if(arr[i][j] == 2 && arr[i][j+1] == 1 && arr[i+1][j] == 3 && arr[i+1][j+1] == 4){
				for(int k = 1; 1; k++){
					bool q2 = sum(2, i-k, i, j-k, j)==k*k;
					bool q1 = sum(1, i-k, i, j, j+k)==k*k;
					bool q3 = sum(3, i, i+k, j-k, j)==k*k;
					bool q4 = sum(4, i, i+k, j, j+k)==k*k;
					if(q1 && q2 && q3 && q4){
						
					}	
					else{
						k--;
						//cout << i << " " << j << " " << k << endl;
						sz[i][j] = k;
						break;
					}
				}
			}
		}
	}
	for(int q = 1; q<=Q; q++){
		cin >> bx[q] >> by[q] >> tx[q] >> ty[q];
	}
	for(int k = 1; k<=N/2; k++){
		for(int i = 1; i<N; i++){
			for(int j = 1; j<M; j++){
				pre[0][i][j] = sz[i][j] >= k;
				pre[0][i][j] += pre[0][i][j-1] + pre[0][i-1][j] - pre[0][i-1][j-1];
				//cout << i << " " << j << " " << pre[0][i][j] << endl;
			}
		}
		for(int q = 1; q<=Q; q++){
			if(tx[q]-bx[q]+1 >= 2*k && ty[q]-by[q]+1 >= 2*k){
				//cout << bx[q]+k-1 << " " << by[q]+k-1 << " " << tx[q]-k << " " << ty[q]-k << endl;
				if(sum(0, bx[q]+k-2, tx[q]-k, by[q]+k-2, ty[q]-k)){
					ans[q] = k;
				}
			}
		}
	}
	for(int q = 1; q<=Q; q++){
		cout << 4*ans[q]*ans[q] << "\n";
	}
}