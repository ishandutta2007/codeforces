a,b,c,d = list(map(int ,raw_input().split()))
pole = []
for row in range (40):
    pole.append(['A']*50)
for row in range (10):
    pole.append(['D']*50)
for i in range(b):
    pole[(i // 25) *2 ][(i %25) *2] = 'B'
for i in range(c):
    pole[ 8 + (i // 25) *2 ][(i %25) *2] = 'C'
for i in range(d-1):
    pole[ 16 + (i // 25) *2 ][(i %25) *2] = 'D'
for i in range(a-1):
    pole[41  + (i // 25) *2 ][(i %25) *2] = 'A'
print('50 50')
for row in range(50):
    print(''.join(pole[row]))