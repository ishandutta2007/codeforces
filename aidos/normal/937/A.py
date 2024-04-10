n = int(input())
a = set(map(int, input().split()))
t = len(a)
if 0 in a:
    t -= 1
print(t)