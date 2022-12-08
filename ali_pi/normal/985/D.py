def f(mid, h):
    if mid <= h:
        return mid * (mid + 1) // 2
    p = (mid - h + 1) // 2
    return ((h+h+p-1)*p)//2+(mid-p)*(mid-p+1)//2
n, h = map(int,raw_input().split())
l, r = 0, 10000000000
while l + 1 < r:
	mid = (l+r) // 2
	if f(mid, h) >= n:
		r = mid
	else:
		l = mid
print(r)