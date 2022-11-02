n = int(input())
a = input()
if n > 26:
    print(-1)
else:
    print(n-len(set(a)))