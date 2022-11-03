n, m = map(int, input().split())
a = set(map(int, input().split()))
b = set(map(int, input().split()))

t = a & b
if t:
    print(min(t))
else:
    c = min(a)
    d = min(b)
    
    print(str(min(c, d)) + str(max(c, d)))