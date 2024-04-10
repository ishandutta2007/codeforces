from bisect import bisect_right
import sys
input = sys.stdin.buffer.readline

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        xlst = list(map(int, input().split()))
        _ = input()
        xlst.sort()
        cnt = []
        xlst.append(10 ** 15)
        r = 0
        for i, x in enumerate(xlst[:-1]):
            while xlst[r] <= x + k:
                r += 1
            cnt.append(r - i)
        max_cnt = 0
        mc_lst = []
        for c in cnt[::-1]:
            max_cnt = max(max_cnt, c)
            mc_lst.append(max_cnt)
        mc_lst = mc_lst[::-1]
        mc_lst.append(0)
        ans = 0
        for i, x in enumerate(xlst[:-1]):
            pos = bisect_right(xlst, x + k)
            ans = max(ans, cnt[i] + mc_lst[pos])
        print(ans)
main()