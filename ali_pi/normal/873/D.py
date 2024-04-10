n,m = list(map(int, raw_input().split()))
res = []
def solve(begin, end, rem):
	#print('Solve:', begin, end, rem)
	if rem<2:
		res.extend(range(begin,end))
		return rem
	if end-begin==1:
		res.append(begin)
		return rem
	rem -= 2
	mid = (begin+end+1)//2
	rem = solve(mid, end, rem)
	rem = solve(begin, mid, rem)
	return rem
rem = solve(1, n+1, m-1)
if rem == 0:
	print(' '.join(map(str, res)))
else:
	print(-1)