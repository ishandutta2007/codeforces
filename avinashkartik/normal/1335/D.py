from math import *
from collections import *
t = int(input())
for y in range(t):
	l = []
	for i in range(9):
		l.append(list(input()))
	if(l[0][0] == '1'): l[0][0] = '2'
	else: l[0][0] = '1' 
	if(l[1][3] == '1'): l[1][3] = '2'
	else: l[1][3] = '1' 
	if(l[2][6] == '1'): l[2][6] = '2'
	else: l[2][6] = '1' 
	if(l[3][1] == '1'): l[3][1] = '2'
	else: l[3][1] = '1' 
	if(l[4][4] == '1'): l[4][4] = '2'
	else: l[4][4] = '1' 
	if(l[5][7] == '1'): l[5][7] = '2'
	else: l[5][7] = '1' 
	if(l[6][2] == '1'): l[6][2] = '2'
	else: l[6][2] = '1' 
	if(l[7][5] == '1'): l[7][5] = '2'
	else: l[7][5] = '1' 
	if(l[8][8] == '1'): l[8][8] = '2'
	else: l[8][8] = '1' 
	for i in range(9):
		print("".join(l[i]))