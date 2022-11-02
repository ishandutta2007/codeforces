t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    if n > 2 or (s[0] < s[1]):
        print('YES')
        print(2)
        print(s[0], s[1:])
    else:
        print('NO')