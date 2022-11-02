n = int(input())
s = set(input().split())
ans = len(s)
if '0' in s:
    ans -= 1
print(ans)