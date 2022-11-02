n = int(input())
a = []
i = 1
while i * i <= n:
    if n % i == 0:
        a.append(i)
        if n  != i * i:
            a.append(n//i)
    i += 1
a = sorted(a)
ans = []
for i in a[::-1]:
    x = n//i
    print((x * (x-1)//2) * i + x)