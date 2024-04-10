n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
p = [0]*(n+1)
for i in range(n):
    p[a[i]] = i
t = 0
for i in range(n):
    if p[b[i]] >= t:
        print(p[b[i]]-t + 1, end = ' ')
        t = p[b[i]] + 1
    else:
        print(0, end = ' ')