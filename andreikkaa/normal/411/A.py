s = input()
l, b, d = False, False, False

for i in s:
    if 'a' <= i <= 'z':
        l = True
    elif 'A' <= i <= 'Z':
        b = True
    elif '0' <= i <= '9':
        d = True

print("Correct" if l and b and d and len(s) >= 5 else "Too weak")