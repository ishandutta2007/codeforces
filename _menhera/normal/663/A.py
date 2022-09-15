import sys

X = sys.stdin.read()

a = X.split()

plus, minus = 1, 0
for i in a:
	if i=='+': plus += 1
	if i=='-': minus += 1

N = int(a[-1])

def calcmaxv(p, m, calc): return p*N - m + calc
def calcminv(p, m, calc): return p - m*N + calc

now = 0
if calcminv(plus, minus, now)>N:
	print ("Impossible")
	quit()
if calcmaxv(plus, minus, now)<N:
	print ("Impossible")
	quit()
sign = +1
for j in range(len(a)):
	i = a[j]
	if i=='+':
		sign = +1
		continue
	if i=='-':
		sign = -1
		continue
	if i!='?': continue
	maxv = calcmaxv(plus, minus, now)
	if sign>0:
		a[j] = str(max(2*N-maxv, 1))
		now += max(2*N-maxv, 1)
	else:
		a[j] = str(min(N, 1+maxv-N))
		now -= min(N, 1+maxv-N)
	if sign>0: plus-= 1
	else: minus -= 1

print ("Possible")
print (" ".join(a))