import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, p = I()
a = I()
a.sort()
m = a[n-1]

lo = [0]*n
# lo[i] = how many numbers at most m-i
r = n-1
lo[0] = n
i = 1
while i < n:
    while r >= 0 and a[r] > m-i:
        r -= 1
    lo[i] = r+1
    i += 1

ans = []
kill = [False]*p
for i in range(n):
    # check if m-i works
    if m-i <= 0:
        break
    kill[(lo[i]+i)%p] = True
    #print(i, kill)
    if kill[i%p] or n-i >= p:
        continue
    ans.append(m-i)

ans.reverse()
print(len(ans))
print(*ans)