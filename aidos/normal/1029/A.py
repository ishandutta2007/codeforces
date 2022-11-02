n, k = map(int, input().split())
t = input()
s = ''
while k > 0:
    i = n-1
    while i > 0 and not s.endswith(t[:i]):
        i -= 1
    s += t[i:]
    k -= 1
print(s)