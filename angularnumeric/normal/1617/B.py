from math import gcd

def find_triplets(n):
    n = n - 1
    for i in range(2, n):
        if gcd(i, n - i) == 1:
            return (i, n - i, 1)


for _ in range(int(input())):
    n = int(input())
    print(*find_triplets(n))