import sys

# ____ CODE ____

def main():
	n = int(input())
	
	c1 = [0] * 6
	c2 = [0] * 6

	for i in input().split():
		c1[int(i)] += 1
	for i in input().split():
		c2[int(i)] += 1
	
	ans = 0
	for i in range(6):
		if (c1[i] + c2[i]) % 2 == 1:
			print(-1)
			return
		ans += abs((c1[i] + c2[i]) // 2 - c1[i])
	print(ans // 2)

# ____ CODE ____

_fin = sys.stdin
_fout = sys.stdout
if "ANDREIKKAA" in sys.argv:
	_fin = open("input.txt", "r")
	#_fout = open("output.txt", "w")
	pass
else:
	#_fin = open("input.txt", "r")
	#_fout = open("output.txt", "w")
	pass

if _fin:
	sys.stdin = _fin
if _fout:
	sys._stdout = _fout

main()