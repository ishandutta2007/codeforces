import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    blst.sort(reverse = True)
    b_score = sum(blst[:n - n // 4])
    bpos = n - n // 4
    ans = 0
    alst.sort()
    a_score = sum(alst[n // 4:])
    ap = n // 4
    while a_score < b_score:
        n += 1
        ans += 1
        blst.append(0)
        alst.append(100)
        if n % 4 == 0:
            a_score += 100
            a_score -= alst[ap]
            ap += 1
        else:
            b_score += blst[bpos]
            bpos += 1
            a_score += 100
    
    print(ans)

            
for _ in range(int(input())):
    main()