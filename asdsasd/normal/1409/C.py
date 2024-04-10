def main():
    t = int(input())
    for _ in range(t):
        n, x, y = map(int, input().split())
        ans = 10 ** 10
        dd = -1
        d = y - x
        for i in range(1, d + 1):
            if d % i != 0:
                continue
            cnt = d // i + 1
            if cnt > n:
                continue
            tmp = (x - 1) % i + 1
            ans_sub = max(y, tmp + i * (n - 1))
            if ans_sub < ans:
                ans = ans_sub
                dd = i
        lst = []                
        for j in range(n):
            lst.append(ans)
            ans -= dd
        print(*lst)
main()