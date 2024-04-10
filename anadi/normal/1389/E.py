import math

t = int(input())

for _ in range(t):
	m, d, w = [int(s) for s in input().split()]
	M = min(m, d)
	
	if d == 1:
		print(M * (M - 1) // 2)
		continue
	
	w //= math.gcd(w, d - 1)
	all_val = M // w
	up_idx = M % w
	print(up_idx * (all_val + 1) * all_val // 2 + (w - up_idx) * (all_val - 1) * all_val // 2)