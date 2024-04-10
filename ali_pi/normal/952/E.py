N = input()
A = 0
for _ in range(N):
    if raw_input().split()[1]=='hard':
        A += 1
B = N-A
if A>B:
    A,B = B,A
n = 1
while not (A<=(n*n)//2 and B<=(n*n)//2+(n%2)):
    n += 1
print(n)