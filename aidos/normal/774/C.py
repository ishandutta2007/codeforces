n = int(input())
s = []
if n % 2 == 1:
    s.append('7')
    n -= 3
for i in range(n//2):
    s.append('1')
print(''.join(s))