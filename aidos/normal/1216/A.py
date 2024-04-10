n = int(input())
s = input()
a = []
cnt = 0
for i in range(0, n, 2):
    if s[i] == s[i+1]:
        a.append('a')
        a.append('b')
        cnt += 1
    else:
        a.append(s[i])
        a.append(s[i+1])

print(cnt)
print(''.join(a))