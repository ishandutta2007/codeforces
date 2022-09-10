#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
pair <PII, int> seg[N];

bool cmp(pair <PII, int> a, pair <PII, int> b){
	if(a.st.st == b.st.st)
		return a.st.nd > b.st.nd;
	return a.st.st < b.st.st;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &seg[i].st.st, &seg[i].st.nd),
		seg[i].nd = i;
	sort(seg + 1, seg + n + 1, cmp);
	
	for(int i = 2; i <= n; ++i)
		if(seg[i].st.nd <= seg[i - 1].st.nd){
			printf("%d %d\n", seg[i].nd, seg[i - 1].nd);
			return 0;
		}
	
	printf("-1 -1\n");
	return 0;
}