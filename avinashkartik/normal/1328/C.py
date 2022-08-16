from math import *
t = int(input())
for y in range(t):
	n = int(input())
	s = input()
	f = 0
	a = ''
	b = ''
	for i in s:
		if f == 0:
			if i == '2':
				a += '1'
				b += '1'
			elif i == '1':
				a += '1'
				b += '0'
				f = 1
			else:
				a += '0'
				b += '0'
		else:
			if i == '2':
				a += '0'
				b += '2'
			elif i == '1':
				a += '0'
				b += '1'
			else:
				a += '0'
				b += '0'
	print(a)
	print(b)