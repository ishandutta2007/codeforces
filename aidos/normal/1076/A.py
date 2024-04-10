n = int(input())
s = input()
for i in range(1, n):
    if s[i-1] > s[i]:
        print(s[:i-1] + s[i:])
        exit(0)
print(s[:n-1])