from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
mod = 10**9 + 7

t = int(input())
for y in range(t):
	s = input()
	l = len(s)
	#print(s[l-4:l])
	if(s[l-2:l] == "po"):
		print("FILIPINO")
	elif(s[l-4:l] == "desu" or s[l-4:l] == "masu"):
		print("JAPANESE")
	else:
		print("KOREAN")