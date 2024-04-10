n = int(input())
l_1 = [0] * n
r_1 = [0] * n
l_2 = [0] * n
r_2 = [0] * n
l = []
r = []
for i in range(n):
	x,y = map(int,input().split())
	l.append(x)
	r.append(y)
	if i == 0:
		l_1[i] = x
		r_1[i] = y
	else:
		l_1[i] = max(l_1[i - 1],x)
		r_1[i] = min(r_1[i - 1],y)
for i in range(n - 1,-1,-1):
	if i == n - 1:
		l_2[i] = l[i]
		r_2[i] = r[i]
	else:
		l_2[i] = max(l[i],l_2[i + 1])
		r_2[i] = min(r[i],r_2[i + 1])
i_max = 0
for i in range(n):
	if i == 0:
		e = l_2[i + 1]
		t = r_2[i + 1]
		i_max = max(i_max,max(0,t - e))
	elif i == n - 1:
		e = l_1[i - 1]
		t = r_1[i - 1]
		i_max = max(i_max,max(0,t - e))
	else:
		e = l_1[i - 1]
		t = r_1[i - 1]
		e1 = l_2[i + 1]
		t1 = r_2[i + 1]
		e = max(e,e1)
		t = min(t,t1)
		i_max = max(i_max,max(0,t - e))
print(i_max)