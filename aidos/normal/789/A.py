n, k = map(int, input().split())
a = map(int, input().split())
cnt = 0
for x in a:
    cnt += (x + k - 1)//k

print((cnt+1)//2)