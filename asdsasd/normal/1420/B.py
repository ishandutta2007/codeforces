import sys
input = sys.stdin.readline
from bisect import bisect_right

bin_s = [1]
while bin_s[-1] <= 10 ** 9:
    bin_s.append(bin_s[-1] * 2)


def main():
    n = int(input())
    alst = list(map(int, input().split()))
    cnt = [0 for _ in range(35)]
    for a in alst:
        pos = bisect_right(bin_s, a)
        cnt[pos] += 1
    ans = 0
    for num in cnt:
        ans += num * (num - 1) // 2
    print(ans)

for _ in range(int(input())):
    main()