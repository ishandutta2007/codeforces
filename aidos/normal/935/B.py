n = int(input())
cnt = 0
s = input()
neg = 0
pos = 0
ans = 0
for x in s:
    if x == 'U':
        cnt += 1
    else:
        cnt -= 1
    if cnt > 0 and neg > 0:
        ans += 1
    elif cnt < 0 and pos > 0:
        ans += 1
    if cnt > 0:
        pos = 1
        neg = 0
    elif cnt < 0:
        pos = 0
        neg = 1
print(ans)