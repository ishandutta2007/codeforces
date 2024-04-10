
n = int(input())
s = str(input())

cnt = 0
last = ''
for i in s:
	if i==last:
		cnt = cnt+1
	last = i

print(cnt)