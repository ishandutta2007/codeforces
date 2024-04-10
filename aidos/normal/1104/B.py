a = input()
n = len(a)
b = [0] * n
l = 0
ans = 0
cnt = 0
for x in a:
    if l > 0 and x == b[l-1]:
        l-=1
        cnt += 1
    else:
        b[l] = x
        l += 1
if cnt % 2 == 0:
    print('No')
else:
    print('Yes')