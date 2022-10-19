#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, u, v;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		bool con = 1, all = 1;
		cin >> n >> u >> v;
		int lastpos;
		cin >> lastpos;
		rep(i, n-1){
			int nowpos;
			cin >> nowpos;
			if(nowpos != lastpos) all = 0;
			if(nowpos < lastpos - 1 || nowpos > lastpos + 1) con = 0;
			lastpos = nowpos;
		}
		if(!con) cout << "0" << endl;
		else if(!all) cout << min(u, v) << endl;
		else cout << v + min(u, v) << endl;  
	}
	return 0;
}