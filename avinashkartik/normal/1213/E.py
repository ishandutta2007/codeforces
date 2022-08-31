from math import *
n = int(input())
ss = input()
t = input()
s = ['' for i in range(15)]
s[1] = 'abc'*n
s[2] = 'acb'*n
s[3] = 'bac'*n
s[4] = 'bca'*n
s[5] = 'cab'*n
s[6] = 'cba'*n
s[7] = 'a'*n + 'b'*n + 'c'*n
s[8] = 'a'*n + 'c'*n + 'b'*n
s[9] = 'b'*n + 'a'*n + 'c'*n
s[10] = 'b'*n + 'c'*n + 'a'*n
s[11] = 'c'*n + 'a'*n + 'b'*n
s[12] = 'c'*n + 'b'*n + 'a'*n
for i in range(1,13):
	if ss not in s[i] and t not in s[i]:
		print("YES")
		print(s[i])
		break