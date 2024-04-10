n = int(input())
a = list(map(int, input().split()))

ans = 0

while True:
    v = max(a[1:])
    p = a[1:].index(v) + 1
    
    if a[0] > v:
        break
    
    a[p] -= 1
    a[0] += 1
    ans += 1

print(ans)