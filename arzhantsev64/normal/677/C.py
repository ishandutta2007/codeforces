def ordd(s):
    if s=='-':
        return 62
    elif s=='_':
        return 63
    elif s in '0123456789':
        return int(s)
    elif ord('a')<=ord(s)<=ord('z'):
        return ord(s)-61
    elif ord('A')<=ord(s)<=ord('Z'):
        return ord(s)-55
s=input()
b=""
res=1
h=''
for i in range(0,len(s)):
    h=bin(ordd(s[i]))[2::]
    d='0'*(6-len(h))
    b+=(d+h)
print((3**b.count('0'))%(10**9+7))