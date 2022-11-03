s = input()
ans = 0
for i in s:
    if (i in 'aeiou') or (i in '13579'):
        ans += 1
print(ans)