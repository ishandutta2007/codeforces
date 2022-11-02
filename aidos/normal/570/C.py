n, m = map(int, input().split())
a = list(input())
res=0
b = []
for i in range(1, n):
    if a[i]+a[i-1] =='..':
        res += 1
for i in range(m):
    g, c = input().split()
    p = int(g)-1
    if p > 0 and a[p-1] + a[p] == '..':
        res -= 1
    if p + 1 < n and a[p+1] + a[p] == '..':
        res -= 1
    a[p] = c
    
    if p > 0 and a[p-1] + a[p] == '..':
        res += 1
    if p + 1 < n and a[p+1] + a[p] == '..':
        res += 1
    b.append(str(res))
print(' '.join(b))