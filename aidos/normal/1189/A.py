n = int(input())
s = input()
a = list(map(int, list(s)))
if sum(a) * 2 == n:
    print(2)
    print(s[0], s[1:])
else:
    print(1)
    print(s)