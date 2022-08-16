r,c,d = map(int,input().split())
ctr = ctc = 0
if(d>r or r%d == 0):
    ctr = r
else:
    ctr = r//d + 1
    ctr *= r-(r//d)*d
if(d>c or c%d == 0):
    ctc = c
else:
    ctc = c//d + 1
    ctc *= c-(c//d)*d

print(ctr*ctc)