#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, m;
bool used[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n)
			used[i] = 0;
		rep(i, m){
			int a, b, c;
			cin >> a >> b >> c;
			used[b - 1] = 1;
		}
		int pos = 0;
		rep(i, n){
			if(!used[i]){
				pos = i;
				break;
			}
		}
		rep(i, n)
			if(i != pos){
				cout << i + 1 <<" " << pos + 1 << endl;
			}
	}
	return 0;
}