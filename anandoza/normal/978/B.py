n = int(raw_input())

s = raw_input()

c = [x for x in s]
c = ['1' if x == 'x' else '0' for x in s]
s = ''.join(c)
t = s.split('0')
answer = 0
for i in t:
    if len(i) - 2 >= 0:
        answer += len(i) -2
    
print answer