#include <bits/stdc++.h>
using namespace std;
int n, m, pos[110], hp[110], arr[110], b[110], rec[110];
bool chk[110];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d", pos+i, hp+i);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d", arr+i);
	}
	for(int x=1; x<=n; x++) {
		for(int i=1; i<=n; i++) b[i] = arr[i];
		for(int i=1; i<=m; i++) chk[i] = 0;
		int k;
		for(k=1; k<=m; k++) {
			int idx = -1;
			for(int i=1; i<=m; i++) {
				if(chk[i]) continue;
				if(x == pos[i]) idx = i;
				else if(x < pos[i]) {
					int curHp = hp[i], f = 1;
					for(int j=pos[i]; j>=x; j--) {
						if(b[j] < 0) {
							if(-b[j] > curHp) { f = 0; break; }
							else curHp -= -b[j];
						} else curHp += b[j];
					}
					if(f) idx = i;
				} else {
					int curHp = hp[i], f = 1;
					for(int j=pos[i]; j<=x; j++) {
						if(b[j] < 0) {
							if(-b[j] > curHp) { f = 0; break; }
							else curHp -= -b[j];
						} else curHp += b[j];
					}
					if(f) idx = i;
				}
			}
			if(idx == -1) break;
			chk[idx] = 1;
			//printf("idx:%d\n", idx);
			rec[k] = idx;
			for(int i=min(pos[idx], x); i<=max(pos[idx], x); i++)
				b[i] = 0;
		}
		if(k == m + 1) {
			printf("%d\n", x);
			for(int i=1; i<=m; i++) printf("%d ", rec[i]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}