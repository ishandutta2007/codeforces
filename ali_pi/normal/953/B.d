module main;

import std.c.stdio;
import std.algorithm;

long gcd(long a, long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(string[] argv)
{
	int n;
	scanf("%d", &n);
	int [] a = new int[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a);
	long m = 0;
	for(int i = 0; i < n-1; ++i) {
	    m = gcd(a[i+1]-a[i], m);
	}
	long add = 0;
	for(int i = 0; i < n-1; ++i) {
	    add += (a[i+1]-a[i]) / m - 1;
	}
	printf("%d\n", add);
	return 0;
}