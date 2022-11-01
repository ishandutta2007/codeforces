s = input()
if s[0] == '-':
    a = int(abs(int(s)) - 1)
else:
    a = int(s)
if a < 2 ** 7:
    print('byte')
elif a < 2 ** 15:
    print('short')
elif a < 2147483648:
    print('int')
elif a < 9223372036854775808:
    print('long')
else:
    print('BigInteger')