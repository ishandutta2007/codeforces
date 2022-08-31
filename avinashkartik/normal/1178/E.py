s = input()
n = len(s)
l = 0
h = n-1
ans = []
while(h >= l):
    if s[l] == s[h]:
        ans.append(s[l])
        l += 1
        h -= 1
    elif s[l+1] == s[h]:
        l += 1
    elif s[l] == s[h-1]:
        h -= 1
    else:
        h -= 1
        l += 1
n = len(ans)
for i in range(n):
    print(ans[i],end = "")
for i in range(n-2,-1,-1):
    print(ans[i],end = "")
print()