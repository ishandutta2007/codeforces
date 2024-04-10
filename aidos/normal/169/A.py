n, a, b = map(int, input().split())
c = sorted(map(int, input().split()))
print(c[b] - c[b-1])