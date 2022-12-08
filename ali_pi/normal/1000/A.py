from collections import*
n=input()
I=lambda:Counter(raw_input()for _ in[0]*n)
a,b=I(),I()
print(sum(max(0,v-b[k])for k,v in a.items()))