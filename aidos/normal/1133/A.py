a, b = map(int, input().split(':'))
c, d = map(int, input().split(':'))
h = (a*60 + b + c * 60 + d)//120
m = ((a*60 + b + c * 60 + d)//2) % 60
d = '0000' + str(h)
m = '0000' + str(m)
print(''.join([d[-2:], ':', m[-2:]]))