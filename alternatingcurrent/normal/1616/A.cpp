#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
bool has[222];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		memset(has, 0, sizeof(has));
		int cnt = 0;
		rep(i, n){
			int a;
			cin >> a;
			if(has[a + 100])
				a = -a;
			if(!has[a + 100])
				has[a + 100] = 1, cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}