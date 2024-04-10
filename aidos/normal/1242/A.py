n = int(input())
x = n
while x % 2 == 0:
    x //= 2
if n == 1:
    print(1)
    exit(0)
if x == 1:
    print(2)
    exit(0)
if x != n:
    print(1)
    exit(0)
x = n
for i in range(3, 10**6, 2):
    if x % i == 0:
        while x % i == 0:
            x//=i
        if x != 1:
            print(1)
            exit(0)
        print(i)
        exit(0)
print(n)