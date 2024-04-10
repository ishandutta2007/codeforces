#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, D[256], p[200000], cnt, S[8];
bool chk[1000010];
long long w[8];
int Sum(long long a){
	long long i;
	int r = 0;
	for (i = 1; p[i]*p[i]<=a && i <= cnt; i++){
		while (a%p[i] == 0){
			a /= p[i];
			r++;
		}
	}
	if (a != 1)r++;
	return r;
}
int main()
{
	int i, j, k, l, c, x, y;
	for (i = 2; i <= 1000; i++){
		if (chk[i])continue;
		for (j = i*i; j <= 1000000; j += i)chk[j] = true;
	}
	for (i = 2; i <= 1000000; i++){
		if (!chk[i])p[++cnt] = i;
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%lld", &w[i]);
	}
	sort(w, w + n);
	for (i = 0; i < n; i++){
		S[i] = Sum(w[i]);
	}
	for (i = 0; i < (1 << n); i++)D[i] = 999999999;
	long long t;
	for (i = 0; i < n; i++){
		if (i == 0){
			D[1] = S[0] + 1;
			if (S[0] == 1)D[1] = 1;
			continue;
		}
		for (j = (1 << i - 1); j < (1 << i); j++){
			if (D[j] == 999999999)continue;
			for (k = 0; k < (1 << i); k++){
				if ((j&k) != k)continue;
				t = w[i];
				c = 0;
				for (l = 0; l < i; l++){
					if ((1 << l)&k){
						if (t%w[l])break;
						t /= w[l];
						c += S[l];
					}
				}
				if (l != i)continue;
				x = (1 << i) + (j^k);
				y = D[j] + S[i] - c + 1;
				if (S[i] == 1) y--;
				if (D[x] > y)D[x] = y;
			}
		}
	}
	int res = 999999999;
	for (i = 1 << (n - 1); i < (1 << n); i++){
		c = 0;
		for (j = 0; j < n; j++){
			if ((1 << j)&i)c++;
		}
		if (c == 1){
			if (res > D[i])res = D[i];
		}
		else if (res>D[i] + 1)res = D[i] + 1;
	}
	printf("%d\n", res);
}