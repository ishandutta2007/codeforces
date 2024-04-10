n = int(input())
s = input()

ans = "YES"

for i in range(26):
    A = chr(ord('A') + i)
    a = chr(ord('a') + i)
    if A not in s and a not in s:
        ans = "NO"
print(ans)