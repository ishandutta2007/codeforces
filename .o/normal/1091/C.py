N = int(input())
def f(x):
  y = N//x
  return y + x * y * (y-1) // 2
ans = set()
for i in range(1,32000):
  if N % i == 0:
    ans.add(f(i))
    ans.add(f(N//i))
print(" ".join(str(x) for x in sorted(ans)))