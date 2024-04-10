s = input()
x = (len(s) + 1)//2
if s == '1' + '0' * (2*x-2):
    x -= 1
if s == '0':
    print(0)
else:
    print(x)