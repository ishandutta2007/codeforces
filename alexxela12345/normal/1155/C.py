from math import gcd
import sys

n, m = list(map(int, input().split()))
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

cur_gcd = 0
for i in range(1, n):
    cur_gcd = gcd(cur_gcd, arr1[i] - arr1[i - 1])
for i in range(m):
    if cur_gcd % arr2[i] == 0:
        print("YES")
        print(arr1[0], i + 1)
        sys.exit(0)
print("NO")