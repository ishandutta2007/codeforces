n, k = map(int, input().split())
s = sorted(set(input()))
x=s[0]
st = ord('a') - 1
ans = ord(x) - st
cnt = 1
for i in range(1,len(s)):
    if cnt == k:
        break
    if ord(s[i]) - ord(x) > 1:
        x = s[i]
        ans += ord(x) - st
        cnt += 1

if cnt == k:
    print(ans)
else:
    print(-1)