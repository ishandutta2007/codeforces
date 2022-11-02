t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    print(min(sum(map(int, input().split())), m))