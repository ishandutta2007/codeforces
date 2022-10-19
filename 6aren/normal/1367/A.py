t = int(input())
while t > 0:
    b = input()
    res = ''
    res += b[0]
    i = 1
    while i < len(b):
        res += b[i]
        i += 2
    print(res)
    t -= 1