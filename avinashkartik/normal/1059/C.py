from math import *
def rec(n,ct):
	if(n == 1):
		return [ct]
	elif(n == 2):
		return [ct,2*ct]
	elif(n == 3):
		return [ct,ct,3*ct]
	else:
		cnt = 0
		for j in range(1,n+1):
			if(j%2 == 1): cnt += 1
		ans = [ct]*cnt
		ans += rec(n//2,ct*2)
		return ans
n = int(input())
print(*rec(n,1))