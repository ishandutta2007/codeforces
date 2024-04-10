a = input()
ans = 0
last = 'a'
for i in a:
    d = abs(ord(last) - ord(i))
    ans += min(d, 26-d)
    last = i
print(ans)