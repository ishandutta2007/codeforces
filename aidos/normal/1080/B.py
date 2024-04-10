q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    ans = 0
    l -= 1
    if r % 2==0:
        ans += r//2
    else:
        ans += (r//2) - r
    
    if l % 2 == 0:
        ans -= l//2
    else:
        ans -= l//2 - l
    print(ans)