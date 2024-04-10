a, b, x = map(int, input().split())
ans = ""
for i in range((x + 1) // 2):
	ans += "10"
	a -= 1
	b -= 1
answ = ""
if x % 2 == 1:
	answ = ('1' * b + ans + '0' * a)
else:
	#print(a, b)
	if a > 0:
		answ = ('0' + '1' * b + ans + '0' * (a - 1))
	else:
		answ = (ans + '1' * b)
print(answ)