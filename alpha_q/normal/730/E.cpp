#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;


struct team {
    int initial, change, id;
    bool operator < (const team &d) const {
        if(initial != d.initial) return initial < d.initial;
        return id > d.id;
    }
} info[MAX];  

bool vis[MAX];
int ans;

void go_down (int n) {

	for (int pos = 1; pos <= n; pos ++) {
		for (int i = 1; i <= n; i ++) {
			if (info[i].change < 0 and not vis[info[i].id]) {
				vis[info[i].id] = true;
				info[i].initial += info[i].change;
				int cur = i;
				while(cur + 1 <= n and info[cur] < info[cur + 1]){
					ans ++;
					swap(info[cur], info[cur + 1]);
					cur ++;
				}
				break;
			}
		}
	}
}

void go_up (int n) {
	for (int pos = 1; pos <= n; pos ++) {
		for (int i = n; i >= 0; i --) {
			if (info[i].change > 0 and not vis[info[i].id]) {
				vis[info[i].id] = true;
				info[i].initial += info[i].change;
				int cur = i;
				while(cur >= 2 and info[cur - 1] < info[cur]){
					ans ++;
					swap(info[cur], info[cur - 1]);
					cur --;
				}
				break;
			}
		}
	}
}

int main(){

	int n; scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int s, d; scanf ("%d %d", &s, &d);
		info[i] = {s, d, i};
	}

	sort (info + 1, info + n + 1);
	reverse (info + 1, info + n + 1);

	go_down (n); go_up (n);

	printf("%d\n",ans);
	return 0;
}