import sys
input = sys.stdin.readline

n, L = map(int, input().split())
c = list(map(int, input().split()))
a = [c[0]]

for i in range(1, 31):
  cand = [a[-1] * 2]
  if i < n: cand.append(c[i])
  a.append(min(cand))

ans = []
sum = 0

for i in reversed(range(31)):
  if L <= (1<<i):
    ans.append(sum + a[i])
  else:
    L -= (1<<i)
    sum += a[i]
  
print(min(ans))