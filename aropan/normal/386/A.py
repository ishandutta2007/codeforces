n = input()
a = sorted([(v, k) for k, v in enumerate(map(int, raw_input().split()))])
print a[-1][1] + 1, a[-2][0]