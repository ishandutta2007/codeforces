t = int(input())
for _ in range(t):
    xyz1 = list(map(int, input().split()))
    xyz2 = list(map(int, input().split()))
    ans = min(xyz1[2], xyz2[1]) * 2
    xyz1[2] -= ans // 2
    xyz2[1] -= ans // 2
    tmp = xyz2[2] - xyz1[0] - xyz1[2]
    tmp = max(tmp, 0)
    ans -= tmp * 2
    print(ans)