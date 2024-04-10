n = int(input())
a = map(int, input().split())
s = 0
for x in a:
    s += x % 2
print(min(s, n-s))