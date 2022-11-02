a = list(map(int, input().split()))
print(max(0, 2 * max(a) + 1 - sum(a)))