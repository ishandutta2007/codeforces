n,k = map(int,raw_input().split())
arr = map(int,raw_input().split())
max_avg = 0
for i in range(k,n+1):
	cur = sum(arr[:i])
	cur_max = cur
	for j in range(i,n):
		cur = cur - arr[j-i] + arr[j]
		if cur>cur_max:
			cur_max = cur
	if cur_max/float(i)>max_avg:
		max_avg = cur_max/float(i)
print(max_avg)