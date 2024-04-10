def get(a, b):
    if a > b:
        return None
    if a==b:
        return [b]
    c = get(a * 2, b)
    if c != None:
        return [a] + c
    c = get(a * 10+1, b)
    if c != None:
        return [a] + c
    return None
    
    
a, b=map(int, input().split())
c = get(a, b)
if c != None:
    print('YES')
    print(len(c))
    for x in c:
        print(x, end = ' ')
else:
    print('NO')