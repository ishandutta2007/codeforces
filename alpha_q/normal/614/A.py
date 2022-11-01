l, r, k = map(int, raw_input().split())
num = 1
while num < l: num = num * k
ret = ""
while num <= r:
	ret = ret + str(num)
	ret = ret + " "
	num = num * k
if ret == "": print -1
else: print ret