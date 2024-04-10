n = int(input())
a = sorted(map(int, input().split()))
print(min(a[-2] - a[0], a[-1] - a[1]))