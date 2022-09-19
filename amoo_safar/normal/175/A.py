def bad(s):
    if(len(s) > 1 and s[0] == '0'): return False
    if(int(s) > 1000000): return False
    return True

s = input()
n = len(s)
ans = -1
for i in range(1, n + 1):
    for j in range(i + 1, n):
        if(bad(s[:i]) and bad(s[i : j]) and bad(s[j :])):
            ans = max(ans, int(s[:i]) + int(s[i:j]) + int(s[j:]))
            
print(ans)