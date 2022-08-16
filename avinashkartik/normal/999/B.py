n = int(input())
s = list(input())
for i in range(1,n+1):
	if(n%i == 0):
		s[:i] = s[:i][::-1]
print("".join(s))