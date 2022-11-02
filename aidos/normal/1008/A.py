x = input()
a = ["a", "o", "u", "i", "e"]
good = 1
x =x + 'n'
n = len(x)
for i in range(1, n):
    if x[i-1]=='n':
        continue
    if x[i-1] in a:
        continue
    if x[i] in a:
        continue
    good = 0
print(('NO', 'YES')[good])