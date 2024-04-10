a, b = map(int,input().split())
def huh(a, b):
    if a * b == 0:
        return a, b
    elif a >= 2 * b:
        return huh(a % (2 * b), b)
    elif b >= 2 * a:
        return huh(a, b % (2 * a))
    else:
        return a, b
a, b = huh(a, b)
print(a, b)