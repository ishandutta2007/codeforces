n = int(input())
a = list(map(int, input().split()))
ans = 0
l = a.index(n)
r = a.index(1)
for i in range(n):
    b = a.copy()
    b[i], b[l] = b[l], b[i]
    ans = max(abs(b.index(1)-b.index(n)), ans)
    b = a.copy()
    b[i], b[r] = b[r], b[i]
    ans = max(abs(b.index(1)-b.index(n)), ans)
print(ans)