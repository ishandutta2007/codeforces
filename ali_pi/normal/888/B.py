raw_input()
i=raw_input()
C=lambda c:i.count(c)
print(min(C('U'),C('D'))*2+min(C('L'),C('R'))*2)