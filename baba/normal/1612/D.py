def test_comb(a, b, x):
    if x == a or x == b:
        return True
    return (a > 0) and (x % a == b % a) and a <= x <= b


def swap(a, b):
    if a > b:
        a, b = b, a
    if a >= b / 2:
        a = b - a
    return a, b


for _ in range(int(input())):
    a, b, x = (int(p) for p in input().split())
    a, b = swap(a, b)
    ret = test_comb(a, b, x)
    while a > 0 and ret is False:
        b = b % a
        a, b = swap(a, b)
        ret |= test_comb(a, b, x)
    print("YES" if ret is True else "NO")