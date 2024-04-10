import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

# two/three pointers too damn annoying
t, = I()
for _ in range(t):
    n, l, r = I()
    a = I()
    a.sort()
    def z(m):
        # how many array elements are below m?
        if a[-1] < m:
            return n
        low = 0
        high = n
        while high-low > 1:
            mid = (low+high)//2
            if a[mid-1] < m:
                low = mid
            else:
                high = mid
        return low
    ans = 0
    for i in range(n):
        x = r+1-a[i]
        y = l-a[i]
        ans += z(x)-z(y)
        if l <= 2*a[i] and 2*a[i] <= r:
            ans -= 1
    print(ans//2)