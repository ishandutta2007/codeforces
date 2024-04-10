from math import gcd

def main():
    n, k = map(int, input().split(" "))
    if n == 1 and k <= 2:
        print("YES")
        return

    if n <= k:
        print("NO")
        return

    x = 1
    for i in range(2, k + 1):
        x = x * i // gcd(x, i)
        if x - 1 > n:
            print("NO")
            return

    if n % x == x - 1:
        print("YES")
    else:
        print("NO")

main()