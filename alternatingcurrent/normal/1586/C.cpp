#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
string s[1000100];
int cntpos = 0;
int pos[1000100];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)
		cin >> s[i];
	for(int j = 0; j < m - 1; j++){
		bool has = 0;
		for(int i = 1; i < n; i++){
			has |= (s[i][j] == 'X' && s[i - 1][j + 1] == 'X');
		}
		if(has)
			pos[cntpos++] = j;
	}
	int Q;
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		int lpos = lower_bound(pos, pos + cntpos, l) - pos;
		int rpos = lower_bound(pos, pos + cntpos, r) - pos - 1;
		if(lpos > rpos)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}