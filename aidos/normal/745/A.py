s = input()
n = len(s)
s = s + s
print(len(set(s[i:i+n] for i in range(n))))