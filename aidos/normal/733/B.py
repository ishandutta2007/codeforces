n = int(input())
ans = 0
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append(x-y)
s = sum(a)
ans = [abs(s)]
for i in range(n):
    ans.append(abs(s - 2*a[i]))
print(ans.index(max(ans)))