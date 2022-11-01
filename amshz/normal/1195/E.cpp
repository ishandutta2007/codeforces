# include <bits/stdc++.h>

using namespace std;

const int N = 3e3+10;
long long int h[N][N];
long long int d[N][N];
long long int g[N];

int main(){
	long long int n ,m ,a ,b ,x ,y ,z ,s;
	cin >> n >> m >> b >> a >> g[0] >> x >> y >> z;
	s = 0;
	for (long long int i=1; i<n*m+5; i++){
		g[i] = (g[i-1]*x+y)%z;
	}
	for (long long int i=1; i<=n; i++){
		for (long long int j=1; j<=m; j++){
			h[i-1][j-1] = g[(i-1)*m+j-1];
			//cout << h[i-1][j-1] << ' ';
		}
		//cout << endl;
	}
	for (long long int i=0; i<n; i++){
		deque <long long int> dq;
		for (long long int j=0; j<m; j++){
			if (dq.size() > 0 and dq[0] <= j-a){
				dq.pop_front();
			}
			while (dq.size() > 0 and h[i][dq.back()] >= h[i][j]){
				dq.pop_back();
			}
			dq.push_back(j);
			if (j >= a-1){
				d[i][j-a+1] = h[i][dq.front()];
				//cout << d[i][j-a+1] << ' ';
			}
		}
		//cout << endl;
	}
	for (long long int i=0; i<m-a+1; i++){
		deque <long long int> dq;
		for (long long int j=0; j<n; j++){
			if (dq.size() > 0 and dq[0] <= j-b){
				dq.pop_front();
			}
			while (dq.size() > 0 and d[dq.back()][i] >= d[j][i]){
				dq.pop_back();
			}
			dq.push_back(j);
			if (j >= b-1){
				s += d[dq.front()][i];
			}
		}
	}
	cout << s;
	return 0;
}