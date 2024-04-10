#include <cstdio>
#include <algorithm>

using namespace std;

int n,arr[100000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	int g=0;
	for(int i=0;i<n;i++) g = __gcd(g,arr[i]);
	
	for(int i=0;i<n;i++) {
		int val = arr[i] / g;
		while(val%2==0) val/=2;
		while(val%3==0) val/=3;
		if(val!=1) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}