n = raw_input()
A = raw_input()
B = raw_input()

res = 0

for i in range(int(n)):
    num = abs(int(A[i]) - int(B[i]))
    res += min(num, 10 - num)

print res