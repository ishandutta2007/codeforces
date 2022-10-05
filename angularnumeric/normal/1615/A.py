import sys
input = sys.stdin.buffer.readline
for t in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ma = max(a)
    mi = min(a)
    diff = ma-mi
    a = [i-mi for i in a]
    s = sum(a)
    if s%n == 0:
        ans = 0
    else:
        ans = 1
    print(min(ans,diff))