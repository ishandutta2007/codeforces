inp = sorted(list(int(x) for x in input().split()))
print(min(sum(inp) // 3, inp[0] + inp[1]))