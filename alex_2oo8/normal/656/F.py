s = input()
p = sum(map(int, s[1:])) + 9 * s.count('0') + 1

print(p)