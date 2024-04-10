t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    B = min(a) + k
    if abs(max(a) - B) > k:
        print(-1)
    else:
        print(B)