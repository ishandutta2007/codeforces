t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    if m + k - n < 0:
        print(k + 1)
    elif 2 * k <= m + k - n:
        print(0)
    else:
        x = (m+k-n)//2 + 1
        print(k-x+1)