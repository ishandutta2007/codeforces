raw_input()
t = list(map(int,raw_input().split()))
d = t[1] - t[0]
print(t[-1] + d * all(u - v == d for u, v in zip(t[1:], t)))