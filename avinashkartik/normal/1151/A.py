n = int(input())
s = input()
m = 200
for i in range(n-3):
    sum = 0
    s1 = abs(ord(s[i]) - ord('A'))
    sum += min(s1,26-s1)
    s2 = abs(ord(s[i+1]) - ord('C'))
    sum += min(s2,26-s2)
    s3 = abs(ord(s[i+2]) - ord('T'))
    sum += min(s3,26-s3)
    s4 = abs(ord(s[i+3]) - ord('G'))
    sum += min(s4,26-s4)
    m = min(m,sum)
print(m)