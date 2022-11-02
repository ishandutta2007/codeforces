n = int(input())
s = input()
a = []
for i in range(n):
    if s[i] == '?':
        a.append('(')
    else:
        a.append(s[i])
cnt = 0
ans = 0
for i in range(n):
    if a[i] == '(':
        cnt+=1
    else:
        cnt -= 1
    ans = min(ans, cnt)

for i in range(n-1, -1, -1):
    if cnt > 0 and s[i] == '?':
        cnt -= 2
        a[i] = ')'
cnt = 0
b = []
for i in range(n):
    if a[i] == '(':
        cnt += 1
    else:
        cnt -= 1
    b.append(cnt)
if len(b) == 1 or min(b[:-1]) <= 0 or b[-1] != 0:
    ans = -1
if ans < 0:
    print(':(')
else:
    print(''.join(a))