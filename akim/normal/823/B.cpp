#include <bits/stdc++.h>

#define f first
#define s second 
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

const int N = (int)1e5+100;

int fv[11][10][4][N];

void add(int (&a)[N], int u, int v) {
	for(; u < N; u |= u + 1) {
		a[u] += v;
	}
}

int get(int (&a)[N], int u) {
	int ret = 0;
	for(; u >= 0; u &= u + 1, u--) {
		ret += a[u];
	}
	return(ret);
}

int get(int (&a)[N], int l, int r) {
	return(get(a, r) - get(a, l - 1));
}

int id(char c) {
	if(c == 'A') return(0);
	if(c == 'T') return(1);
	if(c == 'G') return(2);
	return(3);
}

char buff[20];

int main(){

	string s;
	getline(cin, s);
	int n = s.length();

	for(int i = 0; i < s.length(); i++) {
		for(int l = 1; l <= 10; l++) {
			add(fv[l][i % l][id(s[i])], i, 1);
		}
	}


	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int ty;
		scanf("%d", &ty);
		if(ty == 1) {
			int pos;
			char c;
			scanf("%d %c", &pos, &c);
			pos--;
//			cout << pos << " " << c << endl;
			for(int l = 1; l <= 10; l++) {
				add(fv[l][pos % l][id(s[pos])], pos, -1);
			}
			s[pos] = c;
			for(int l = 1; l <= 10; l++) {
				add(fv[l][pos % l][id(s[pos])], pos, 1);
			}
		} else {
			int l, r;
			string t;
			scanf("%d%d %s", &l, &r, buff);
			l--, r--;
			t = buff;
			int le = t.length();
			int ans = 0;
//			cout << l << " " << r << " " << t << endl;
			for(int i = 0; i < le; i++) {
				ans += get(fv[le][(l + i) % le][id(t[i])], l, r);
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}