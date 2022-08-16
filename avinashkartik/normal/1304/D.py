from collections import *

te = int(input())
for y in range(te):
	n,s = input().split()
	n = int(n)
	st = []
	r = n
	st.append(r)
	r -= 1
	for i in range(n-1):
		if(s[i] == '<'):
			st.append(r)
			r -= 1
		else:
			while(len(st) != 0):
				print(st[-1],end = " ")
				st.pop()
			st.append(r)
			r -= 1
	while(len(st) != 0):
		print(st[-1],end = " ")
		st.pop()
	print()
	l = 1
	st.append(l)
	l += 1
	for i in range(n-1):
		if(s[i] == '>'):
			st.append(l)
			l += 1
		else:
			while(len(st) != 0):
				print(st[-1],end = " ")
				st.pop()
			st.append(l)
			l += 1
	while(len(st) != 0):
		print(st[-1],end = " ")
		st.pop()
	print()