#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const int INF = 1e9 + 7;
const int MX = 1e9 + 9;

int n;

int main(){
	int last = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		if(a > last + 15){
			printf("%d\n", last + 15);
			return 0;
		}
		last = a;
	}
	
	if(90 > last + 15)
		printf("%d\n", last + 15);
	else
		printf("90\n");
	return 0;
}