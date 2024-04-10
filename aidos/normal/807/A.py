n = int(input())
a = [0] * n
b = [0] * n
s = 0
s2=1
for i in range(n):
    a[i], b[i] = map(int, input().split())
    s += abs(b[i] - a[i])
    if i > 0 and a[i-1] < a[i]:
        s2 = 0
if s > 0:
    print('rated')
elif s2:
    print('maybe')
else:
    print('unrated')