import sys
N, M, C = map(int,raw_input().split())
ans = [0] * (N+1)
ls, le = 1, N+1
rs, re = N//2+1, N+1
for _ in range(M):
    p = int(raw_input())
    ii = -1
    if p < C//2+1:
        for i in range(1, N+1):
            if ans[i] == 0 or ans[i] > p:
                ii = i
                break
    else:
        for i in range(N, 0, -1):
            if ans[i] == 0 or ans[i] < p:
                ii = i
                break
    ans[ii] = p
    print(ii)
    sys.stdout.flush()
    if all(x > 0 for x in ans[1:]):
        exit(0)