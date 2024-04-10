s = input()
ans = 0
for i in range(len(s)):
  for j in range(i, len(s)):
    t = s[i:j+1]
    if t != "".join(list(reversed(t))):
      ans = max(ans, j-i+1)
print(ans)