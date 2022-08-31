s = float(input())
a, b, c = map(float, input().split())
if (a == b and b == c and c == 0):
    print('0 0', end = " ")
    print(s)
else:
    print(a * s / (a + b + c), end = " ")
    print(b * s / (a + b + c), end = " ")
    print(c * s / (a + b + c))