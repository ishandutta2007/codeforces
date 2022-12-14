p, k = map(int, input().split())
k = -k

a = []
while p != 0:
  r = p % k
  p //= k
  if r < 0:
    r += -k
    p += 1
  a.append(r)

print(len(a))
print(" ".join(map(str, a)))