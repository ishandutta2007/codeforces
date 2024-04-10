#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

ll T;
int n;
int a[250250];
int stk[2][250250], p[2];
int to[250250];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		p[0] = p[1] = 0;
		for(int i = n - 1; i >= 0; i--){
			while(p[0] && a[stk[0][p[0] - 1]] > a[i])
				p[0]--;
			while(p[1] && a[stk[1][p[1] - 1]] < a[i])
				p[1]--;
//			cout << i << ": " << endl;
//			rep(j, p[0])
//				cout << stk[0][j] << " ";
//			cout << endl;
//			rep(j, p[1])
//				cout << stk[1][j] << " ";
//			cout << endl;
			if(i < n - 1){
				if(a[i + 1] > a[i]){
					int pos = p[0] ? stk[0][p[0] - 1] : n;
					int lb = 0, ub = p[1] - 1;
					while(lb <= ub){
						int mid = (lb + ub) >> 1;
						if(stk[1][mid] > pos)
							lb = mid + 1;
						else
							ub = mid - 1;
					}
//					cout << ub << endl;
					to[i] = stk[1][lb];
				} else {
					int pos = p[1] ? stk[1][p[1] - 1] : n;
					int lb = 0, ub = p[0] - 1;
					while(lb <= ub){
						int mid = (lb + ub) >> 1;
						if(stk[0][mid] > pos)
							lb = mid + 1;
						else
							ub = mid - 1;
					}
					to[i] = stk[0][lb];
				}
			}
			stk[0][p[0]++] = stk[1][p[1]++] = i;
		}
		int now = 0, dist = 0;
		while(now < n - 1)
			now = to[now], dist++;
		cout << dist << endl;
	}
	return 0;
}