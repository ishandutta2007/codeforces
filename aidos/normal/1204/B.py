n, l, r = map(int, input().split())
print(n-l + (2**l) - 1, (n-r) * (2**(r-1)) + (2**r)-1)