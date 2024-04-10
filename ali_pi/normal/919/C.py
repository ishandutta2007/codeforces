import re

n, m, k = map(int,raw_input().split())
s = [raw_input() for _ in range(n)]
if n > 1 and k > 1:
	t = list(map(lambda x: "".join(x), zip(*s)))
	s += t
ans = 0
p = re.compile(r"\.{" + str(k) + ",}")
for i in s:
	ans += sum(map(lambda x: len(x) - k + 1, p.findall(i)))
print(ans)