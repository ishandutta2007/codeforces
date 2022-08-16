from collections import *
n = int(input())
a = list(input())
b = list(input())
ans = []
cb = dict()
cb['?'] = []
for i in range(n):
	if(b[i] not in cb):
		cb[b[i]] = [i]
	else:
		cb[b[i]].append(i)
for i in range(n):
	if(a[i] == '?'):
		continue
	if(a[i] in cb and len(cb[a[i]]) != 0):
		ans.append((i,cb[a[i]][-1]))
		cb[a[i]].pop()
visa = [0 for i in range(n)]
visb = [0 for i in range(n)]
for i in ans:
	visa[i[0]] = 1
	visb[i[1]] = 1
ch = []
for i in range(n):
	if(visa[i] == 0):
		ch.append([a[i],i])
ch.sort()
for i in cb['?']:
	ans.append((ch[-1][1],i))
	visb[i] = 1
	ch.pop()
chb = []
for i in range(n):
	if(visb[i] == 0):
		chb.append(i)
for i in ch:
	if(i[0] != '?'):
		break
	ans.append((i[1],chb[-1]))
	chb.pop()
print(len(ans))
for i in ans:
	print(i[0]+1,i[1]+1)