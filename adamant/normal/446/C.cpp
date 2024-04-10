/*
FENWICK TREES SOLUTION
two query type:
1 l r : add to a[i] (l <= i <= r) a[i] += fibonacci(i)
2 l r : find sum l -> r

f(1) + f(2) ... + f(n) = A + f(n - 1) + f(n) = A + f(n + 1)
= f(1) + f(2) + f(1) + f(2) + ... + f(n - 2) + f(n - 1) 
= f(2) + 2(f(1) + ... + f(n - 2)) + f(n - 1) = 2A + f(n - 1) + f(2)
-> A = f(n) - f(2)
-> f(1 -> n) = f(n) - f(2) + f(n + 1) = f(n + 2) - f(2) (*)

we will solve this problem using 
now what you want for query(l, r) is query(1 -> r) and query(1 -> l - 1)
in general is query(1 -> n)
if there is a whole update range(l, r) before this answer query
if 1 <= l <= r <= n then it will contribute fib(r - l + 1 + 2) - 1 (*)
else if 1 <= l <= n <= r then it will contribute fib(n - l + 1 + 2) - 1 (*)

f(1), f(2) are first two value in (1, n)
which satisfy f(i) = f(i - 1) + f(i - 2)
now when you want to add
fib(k), fib(k + 1), ..., fib(k + r - l) to f(1), ... f(r - l + 1)
f(i) + fib(i + k) = f(i - 1) + fib(i + k - 1) + f(i - 2) + fib(i + k - 2)
f(i) += fib(i + k)
-> f(i) = f(i - 1) + f(i - 2) -> same property

f(1 -> i) = f(1) * fib(i - 2) + f(2) * fib(i - 1)
using d'Ocagne's identity (fib(n + 1) * fib(m) - fib(n) * fib(m + 1) = (-1) ^ n * fib(m - n)
-> (-1) ^ (l - 3) * fib(n - (l - 3)) = fib(l - 2) * fib(n) - fib(l - 3) * fib(n + 1)
-> f(n - l + 1 + 2) = f(2 - l) * f(n) + f(3 - l) * f(n + 1)

f(1 -> n) = f(n + 2) - f(2) = a * fib(n) + b * fib(n + 1) - 1

so we can keep BIT<a, b, c>
1 l r:
	update(l, <fib(2 - l), fib(3 - l), -1)
	update(r + 1, <-fib(2 - l), -fib(3 - l), fib(r - l + 3))
2 l r: (2 r) - (2 l - 1)
	2 n:
		<a, b, c> = query(n)
		ans = a * fib(n) + b * fib(n + 1) + c
*/
#include "bits/stdc++.h"
using namespace std;

const int N = 3e5 + 3, mod = 1e9 + 9;

char c;
int n, q, a[N], f[N];

void read(int& n) {
	while (true) {
		c = _getchar_nolock();
		if (c == ' ' || c == '\n') {
			break;
		}
		n = (n << 1) + (n << 3) + c - '0';
	}
}

void write(int n) {
	if (n > 9) {
		write(n / 10);
		_putchar_nolock(n % 10 + '0');
	} else {
		_putchar_nolock(n + '0');
	}
}

int add(int a, int b) {
	int x = a + b;
	if (x >= mod) {
		x -= mod;
	}
	if (x < 0) {
		x += mod;
	}
	return x;
}

int sub(int a, int b) {
	return add(a, mod - b);
}

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

struct tree_list {
	int a = 0, b = 0, c = 0;
} tree[N];

int fib(int n) {
	if (n >= 0) {
		return f[n];
	}
	if (n & 1) {
		return f[-n];
	}
	return mod - f[-n];
}

void update(int k, int a, int b, int c) {
	while (k <= n) {
		tree[k].a = add(tree[k].a, a);
		tree[k].b = add(tree[k].b, b);
		tree[k].c = add(tree[k].c, c);
		k += k & -k;
	}
}

int query(int k) {
	int a = 0, b = 0, c = 0, n = k;
	while (k >= 1) {
		a = add(a, tree[k].a);
		b = add(b, tree[k].b);
		c = add(c, tree[k].c);
		k -= k & -k;
	}
	return add(add(mul(a, fib(n)), mul(b, fib(n + 1))), c);
}

int main() {
	read(n);
	read(q);
	f[1] = 1;
	for (int i = 2; i <= n + 2; i++) {
		f[i] = add(f[i - 1], f[i - 2]);
	}
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		a[i] = add(a[i], a[i - 1]);
	}
	while (q--) {
		int type = 0, l = 0, r = 0;
		read(type);
		read(l);
		read(r);
		if (type == 1) {
			update(l, fib(2 - l), fib(3 - l), -1);
			update(r + 1, -fib(2 - l), -fib(3 - l), f[r - l + 3]);
		} else {
			write(add(sub(a[r], a[l - 1]), sub(query(r), query(l - 1))));
			_putchar_nolock('\n');
		}
	}
}