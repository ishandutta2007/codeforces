n = int(input())
a = list(map(int, input().split()))
x = min(a)
c = [i for i in range(n) if a[i] == x]
d = [c[i] - c[i-1] for i in range(1, len(c))]
print(min(d))