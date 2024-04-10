#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1100;

int n, a[N][N];
int get(int x){
	int i = 0, j = 0;
	while(i == x)
		i++;
	while(j == x || i == j)
		j++;
	return sqrt(1ll * a[i][x] * a[j][x] / a[i][j]); 
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < n; i++)
		printf("%d ", get(i));
	return 0;
}