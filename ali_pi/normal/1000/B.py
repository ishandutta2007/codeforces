def main():
 n, M = list(map(int, raw_input().split()))
 seq = [0] + list(map(int, raw_input().split())) + [M]
 seq = [seq[i + 1] - seq[i] for i in range(n + 1)]
 ret = [sum([seq[i] for i in range(n + 1) if i % 2 == 0])]
 seq = [seq[i] * ((-1) ** i) for i in range(n + 1)]
 s = 0
 s0 = sum(seq)
 for i in range(n + 1):
  ret.append(-1 + (s - s0 + M) // 2)
  a = seq[i]
  s += a
  s0 -= a
 print(max(ret))
 return 0
main()