import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
m = min(a)

p = [i for i, v in enumerate(a) if v == m]
ans = p[1] - p[0]
for i in range(1, len(p)):
  ans = min(ans, p[i] - p[i-1])

print(ans)