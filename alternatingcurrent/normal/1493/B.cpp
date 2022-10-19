#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

bool ok[12] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
int rev[12] = {0, 1, 5,-1,-1, 2,-1,-1, 8,-1};

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		int h, m;
		string now;
		cin >> h >> m >> now;
		int nh = (now[0] - '0') * 10 + (now[1] - '0');
		int nm = (now[3] - '0') * 10 + (now[4] - '0');
		int ansh = -1, ansm;
		for(int i = nm; i < m; i++){
			int a = nh / 10, b = nh % 10, c = i / 10, d = i % 10;
			if(!ok[a] || !ok[b] || !ok[c] || !ok[d]) continue;
			int rm = rev[b] * 10 + rev[a], rh = rev[d] * 10 + rev[c];
			if(rm < m && rh < h){
				ansh = nh, ansm = i;
				break;
			}
		}
		if(ansh >= 0){
			if(ansh < 10) cout << "0";
			cout << ansh;
			cout << ":";
			if(ansm < 10) cout << "0";
			cout << ansm << endl;
			continue;
		}
		for(int i = nh+1; i < h; i++){
			for(int j = 0; j < m; j++){
				int a = i / 10, b = i % 10, c = j / 10, d = j % 10;
				if(!ok[a] || !ok[b] || !ok[c] || !ok[d]) continue;
				int rm = rev[b] * 10 + rev[a], rh = rev[d] * 10 + rev[c];
				if(rm < m && rh < h){
					ansh = i, ansm = j;
					break;
				}
			}
			if(ansh >= 0) break;
		}
		if(ansh >= 0){
			if(ansh < 10) cout << "0";
			cout << ansh;
			cout << ":";
			if(ansm < 10) cout << "0";
			cout << ansm << endl;
		} else {
			cout << "00:00" << endl;
		}
	}
	return 0;
}