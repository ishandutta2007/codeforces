def solve(s):
    if len(str(s)) == 1:
        return s
    ans1 = solve(s // 10)
    ans2 = solve(s // 10 - 1)
    return max(ans1 * (s % 10), ans2 * 9, 9)


n = int(input())

print(solve(n))