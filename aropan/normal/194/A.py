# map(int, raw_input().split())
# " ".join([])
# [0] * n
# isupper

n, k = map(int, raw_input().split())
print n - min(n, (k - 2 * n))