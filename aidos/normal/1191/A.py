n = int(input())
n %= 4
if n == 2:
    print(1, 'B')
else:
    print((1-n)%4, 'A')