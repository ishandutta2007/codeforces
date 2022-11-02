n, m = map(int, input().split())
a = [0] * n
 
for i in range(m):
    b = list(map(int, input().split()))
    a[b.index(max(b))]+=1
print(a.index(max(a)) + 1)