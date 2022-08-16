n = int(input())
d = dict()
for i in range(n):
    s = input()
    if s not in d:
        print("OK")
        d[s] = 1
    else:
        print(s,end="")
        print(d[s])
        d[s] += 1