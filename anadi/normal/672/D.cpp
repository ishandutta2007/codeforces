#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int mxn = 5e5 + 7;

int n, k;
int T[mxn];

bool check(int val){
	int res = 0;
	for(int i = 1; i <= n; ++i){
		if(T[i] > val)
			break;
		res += val - T[i];
		if(res > k)
			return false;
	}
	
	return res <= k;
}

int BS(int pocz, int kon){
	while(pocz < kon){
		int mid = (pocz + kon + 2)/2;
		if(check(mid))
			pocz = mid;
		else
			kon = mid - 1;
	}
	
	return pocz;
}

bool check2(int val){
	int res = 0;
	for(int i = n; i >= 1; --i){
		if(T[i] < val)
			break;
		res += T[i] - val;
		if(res > k)
			return false;
	}
	
	return res <= k;
}

int BS2(int pocz, int kon){
	while(pocz < kon){
		int mid = (pocz + kon)/2;
		if(check2(mid))
			kon = mid;
		else
			pocz = mid + 1;
	}
	
	return pocz;
}

int main(){
	scanf("%d %d", &n, &k);
	
	LL sum = 0LL;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &T[i]);
		sum += T[i];
	}

	sort(T + 1, T + n + 1);
	
	int mn = BS(1, 1e9);
	int mx = BS2(1, 1e9);
	
	if(sum%n != 0 && mn >= mx)
		puts("1");
	else
		printf("%d\n", max(mx - mn, 0));
	return 0;
}