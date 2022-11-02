n = int(input())
a = map(int, input().split())
b = dict()
mx = 0
for i in a:
    b[i] = b.get(i, 0) + 1
    mx = max(b[i], mx)
print(n-mx)