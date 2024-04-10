raw_input()
l = raw_input().split()
print(max(l.count(x) for x in l))