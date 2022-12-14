c, d = list(map(int, input().split()))
n, m = list(map(int, input().split()))
k = int(input())
kolvo = m * n - k
if kolvo < 0:
	print(0)
	exit()
print(min(c * (kolvo // n), d * n * (kolvo // n)) + min(c, d * (kolvo % n)))