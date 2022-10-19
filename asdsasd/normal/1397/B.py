def main():
    import sys
    input = sys.stdin.buffer.readline
    
    n = int(input())
    alst = list(map(int, input().split()))
    alst.sort()
    one = sum(alst) - n
    ans = one
    num = 1
    while 1:
        cnt = 0
        num2 = 1
        for i in range(n):
            tmp = abs(num2 - alst[i])
            if tmp > ans:
                break
            cnt += tmp
            num2 *= num
        else:
            num += 1
            ans = min(ans, cnt)
            continue
        break
    print(ans)

main()