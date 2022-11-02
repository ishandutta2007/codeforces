x, y, z = map(int, input().split())

s = (x+y)//z

d = x//z + y//z
if s == d:
    print(s, 0)
else:
    print(s, min(z - x % z, z - y % z))