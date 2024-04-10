n, k = map(int, input().split())
b = []
a = map(int, input().split())
s = set()
l = 0
for x in a:
    if x in s:
        continue
    if len(b) - l == k:
        s.remove(b[l])
        l += 1
    b.append(x)
    s.add(x)
b = b[l:][::-1]
print(len(b))
print(' '.join(map(str, b)))