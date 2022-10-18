n = int(input())
a = int(input())
b = int(input())
c = int(input())
if a <= (b - c):
	print(n // a)
	exit(0)
tmp = n // a
n -= b
k = max(n, 0) // (b - c) + 1
if n < 0:
	k -= 1
#print(k)
n = (n + b) - k * (b - c)
#print(n)
print(max(k + max(n // a, n // b), tmp))