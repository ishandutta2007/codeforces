n = int(input())

a = list(map(int, input().split()))

a.sort()

print('Bob' if a.count(a[0]) > n / 2 else 'Alice')