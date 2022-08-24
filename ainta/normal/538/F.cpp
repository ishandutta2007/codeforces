#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[201000], S[201000];
void Do(int K){
	int i, R = 0;
	for (i = 2; i <= n; i++){
		if (w[(i - 2) / K + 1] > w[i])R++;
	}
	printf("%d ", R);
}
int main(){
	int i, j, t, b, e;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for (i = 1; i < n && i < 500; i++){
		Do(i);
	}
	if (n <= 500)return 0;
	for (i = 1; i <= 400; i++){
		for (j = i + 1; j <= n; j++){
			if (w[i] > w[j]){
				b = (j - 2) / i + 1;
				if(i!=1)e = (j - 2) / (i - 1);
				else e = n;
				if(b <= e)S[b]++, S[e + 1]--;
			}
		}
	}
	t = 0;
	for (i = 1; i < n; i++){
		t += S[i];
		if(i >= 500)printf("%d ", t);
	}
}