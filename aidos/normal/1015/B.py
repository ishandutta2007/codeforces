n = int(input())
s = list(input())
t = list(input())
ans = []
for i in range(n):
    for j in range(i,n):
        if s[j] == t[i]:
            for k in range(j, i, -1):
                s[k], s[k-1] = s[k-1], s[k]
                ans.append(k)
            break
if s==t:
    print(len(ans))
    print(' '.join(map(str, ans)))
else:
    print(-1)