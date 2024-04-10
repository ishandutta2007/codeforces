#include<cstdio>
#include<cstring>

int a[10001], b[10001];

int min(int x, int y){return (x < y) ? x : y;}
int P(int x){return (x < 0) ? -x : x;}
int main()
{
int n;
scanf("%d\n", &n);
for(int i = 1; i <= n; i++) a[i] = getchar() - '0';
scanf("\n");
for(int i = 1; i <= n; i++) b[i] = getchar() - '0';
int ans = 0;
for(int i = 1; i <= n; i++) ans += min(P(a[i] - b[i]),min(P(a[i] - 10 - b[i]), P(a[i]+10-b[i])));
printf("%d", ans); 
}