#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;

int n, q;
int place = 1;
int sum = 0, add = 0;

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= q; ++i){
		int t;
		scanf("%d", &t);
		
		if(t == 1){
			int x; scanf("%d", &x);
			if(x < 0)
				x += n;

			sum += x;
			place += x;

			if(place > n)
				place -= n;

			if(sum >= n)
				sum -= n;
		}
		else{
			++add;
			if(place & 1)
				++place;
			else
				--place;
		}
	}
	
	add %= n;
	sum = (n - sum)%n;
	
	int diff = place + sum > n ? place + sum - n : place + sum;
	diff -= 1;

	if(place & 1)
		diff = n - diff;

	for(int i = 1; i <= n; ++i){
		int cur = i + sum > n ? i + sum - n : i + sum;
		if(i & 1)
			cur += diff;
		else
			cur += n - diff;
		
		if(cur > n)
			cur -= n;
		printf("%d ", cur);
		
	}

	return 0;
}