n, m = list(map(int, input().split()))
a = list(map(int, input().split()))  

c = 0
i = 0

while i < n:
    p = m
    while p >= a[i]:
        p -= a[i]
        i += 1
        if i >= n:
            break
    c += 1
print(c)