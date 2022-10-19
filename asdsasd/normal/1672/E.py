import sys
input = sys.stdin.readline

def ask(q, t):
    print(q, t, flush=True)
    if q == "!":
        exit()
    return int(input())

def main():
    n = int(input())
    l = 0
    r = 2020 * n
    while r - l > 1:
        mid = (l + r) // 2
        x = ask("?", mid)
        if x == 0 or x >= 2:
            l = mid
        else:
            r = mid
    ans = r
    for i in range(2, n + 1):
        w = (r - 1) // i
        x = ask("?", w)
        if x != 0:
            ans = min(ans, x * w)
    ask("!", ans)
    
    
main()