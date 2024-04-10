s = input()
s1 = input()
s = s.lower()
s1 = s1.lower()
if(s < s1):
    print(-1)
elif(s1 < s):
    print(1)
else:
    print(0)