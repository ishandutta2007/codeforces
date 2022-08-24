#include<stdio.h>
#include<algorithm>
using namespace std;
int n, Res = 1100000000;
struct rect{
	int x, y;
	bool operator<(const rect &p)const{
		return y - x < p.y - p.x;
	}
}w[1010];
void Do(int h){
	int i, cnt = 0, S = 0;
	for (i = 1; i <= n; i++){
		if (w[i].x > h && w[i].y > h)return;
		if (w[i].y > h){
			cnt++;
			S += w[i].y;
		}
		else S += w[i].x;
	}
	if (cnt * 2 > n)return;
	for (i = 1; i <= n; i++){
		if (w[i].x <= h && w[i].y <= h && w[i].x > w[i].y && (cnt+1)*2 <= n){
			cnt++;
			S -= w[i].x - w[i].y;
		}
	}
	if (Res > S*h)Res = S*h;
}
int main(){
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d%d", &w[i].x, &w[i].y);
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= 1000; i++){
		Do(i);
	}
	printf("%d\n", Res);
}