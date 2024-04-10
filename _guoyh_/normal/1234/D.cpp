# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int q, sz;
string s;
int c[30][NR];
int lowbit(int x){
	return x & (-x);
}
void add(int x, int y, int z){
	while (x < NR){
		c[y][x] += z;
		x += lowbit(x);
	}
}
int find(int x, int y){
	if (x < 0) return 0;
	int ans = 0;
	while (x){
		ans += c[y][x];
		x -= lowbit(x);
	}
	return ans;
}
int main(){
	cin >> s;
	sz = s.size();
	s = '\0' + s;
	for (int i = 1; i <= sz; i++)
		add(i, s[i] - 'a', 1);
	cin >> q;
	for (int i = 0; i < q; i++){
		int x;
		scanf("%d", &x);
		if (x == 1){
			int pos;
			char c;
			cin >> pos >> c;
			add(pos, s[pos] - 'a', -1);
			add(pos, c - 'a', 1);
			s[pos] = c;
		} else {
			int l, r;
			cin >> l >> r;
			int cnt = 0;
			for (int j = 0; j < 26; j++)
				if (find(r, j) - find(l - 1, j)){
					cnt++;
				}
			cout << cnt << endl;
		}
	}
	return 0;
}