n = int(input())
s = input()
print(n - 2 * min(s.count('1'), s.count('0')))