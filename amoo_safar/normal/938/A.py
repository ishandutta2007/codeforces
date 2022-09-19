v = 'aiouey'
n = int(input())
s= input()
o =s[0]
for i in range(1,n):
    if (s[i] in v):
        if s[i-1] not in v:o+=s[i]
    else:o+=s[i]
print(o)