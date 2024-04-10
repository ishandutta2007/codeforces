n,k,x = map(int, input().split())
a = list(map(int, input().split()))
a = a[::-1]
for i in range(k):
    a[i] = min(a[i], x)
print(sum(a))