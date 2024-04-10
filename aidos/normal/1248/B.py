n = int(input())
a = sorted(map(int, input().split()))[::-1]
b = a[:(n+1)//2]
print(sum(b) ** 2 + (sum(a) - sum(b)) ** 2)