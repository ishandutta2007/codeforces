n = int(input())
d = input().split()
a, b = map(int, input().split())
ans = 0
for i in range(a, b):
    ans += int(d[i - 1])
print(ans)