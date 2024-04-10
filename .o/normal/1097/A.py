s = input()
for x in input().split():
  if s[0] == x[0] or s[1] == x[1]:
    print("YES")
    exit()
print("NO")