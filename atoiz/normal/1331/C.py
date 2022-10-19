x = int(input())
y = 0
if x & 1: y = y | 16
if x & 2: y = y | 2
if x & 4: y = y | 8
if x & 8: y = y | 4
if x & 16: y = y | 1
if x & 32: y = y | 32
print(y)