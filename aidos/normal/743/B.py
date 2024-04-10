n, k = map(int, input().split())
while True:
    if 2**n == k:
        print(n+1)
        break
    if k > 2**n:
        k -= 2 ** n
    n -= 1