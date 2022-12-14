n = int(input())
a = [sum(map(int, input().split())) for _ in range(n)]
print(sum(v > a[0] for v in a[1:]) + 1)