n = int(input())
s = input()
for i in range(1, n):
    if ord(s[i]) < ord(s[i-1]):
        print('YES')
        print(i, i + 1)
        exit(0)
print('NO')