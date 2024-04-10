x, y = 0, 0
s = []
def solve():
    c, a, b = input().split()
    a = int(a)
    b = int(b)
    global x
    global y
    if a > b:
        a, b = b, a
    if c == '+':
        if x < a:
            x = a
        if y < b:
            y = b
    elif x <= a and y <= b:
        s.append('YES')
    else:
        s.append('NO')


t = int(input())
for i in range(t):
    solve()
print('\n'.join(s))