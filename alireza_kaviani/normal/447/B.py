s = input()
k = int(input())
l = list(map(int ,input().split()))

m = max(l)
ans = 0
for i in range(len(s)):
    ans += l[ord(s[i]) - 97] * (i + 1)
for i in range(1 , k + 1):
    ans += m * (len(s) + i)
    
print(ans)