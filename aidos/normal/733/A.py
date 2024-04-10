x = 'AEIOUY'
pos = -1
a = input()
ans = 0
n = len(a)
for i in range(n):
    if a[i] in x:
        ans = max(ans, i-pos)
        pos = i
print(max(ans, n-pos))