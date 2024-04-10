n = int(input())
a = sorted(map(int, input().split()))

m = int(input())
b = map(int, input().split())
s = sum(a)
for x in b:
    print(s - a[n-x])