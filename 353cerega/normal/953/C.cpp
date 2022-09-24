#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)scanf("%d", &a[i]);
	int len = 1;
	for(int i = 1; i < n; i++)if(a[i] == a[0])++len; else break;
	if(n%len != 0){printf("NO"); return 0;}
	for(int i = 0; i < n; i += len){
		if(i > 0 && a[i] == a[i - len]){printf("NO"); return 0;}
		for(int j = i + 1; j < i + len; j++)if(a[j] != a[i]){printf("NO"); return 0;}
	}
	printf("YES");
	return 0;
}