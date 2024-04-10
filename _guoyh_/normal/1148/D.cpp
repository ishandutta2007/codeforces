# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
struct Node{
	int a, b;
} arr[MAXN];
int n, sz1, sz2;
int b1[MAXN], b2[MAXN];
bool cmp1(int x, int y){
	return arr[x].a > arr[y].a;
}
bool cmp2(int x, int y){
	return arr[x].a < arr[y].a;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &arr[i].a, &arr[i].b);
		if (arr[i].a < arr[i].b) b1[++sz1] = i;
		else b2[++sz2] = i;
	}
	printf("%d\n", max(sz1, sz2));
	if (sz1 > sz2){
		sort(b1 + 1, b1 + sz1 + 1, cmp1);
		for (int i = 1; i <= sz1; i++) printf("%d ", b1[i]);
		putchar('\n');
	} else {
		sort(b2 + 1, b2 + sz2 + 1, cmp2);
		for (int i = 1; i <= sz2; i++) printf("%d ", b2[i]);
		putchar('\n');
	}
	return 0;
}