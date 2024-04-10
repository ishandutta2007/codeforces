t = int(input())
for _ in range(t):
    n = int(input())
    print((sum(map(int, input().split())) + n-1)//n)