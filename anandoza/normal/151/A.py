n, k, l, c, d, p, nl, np = tuple(int(i) for i in raw_input().split(" "))

print min(k * l / nl, c * d, p / np) / n