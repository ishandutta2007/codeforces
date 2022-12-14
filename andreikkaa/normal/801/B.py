s = input()
t = input()

for i in range(len(s)):
    if t[i] > s[i]:
        print(-1)
        exit()
print(t)