import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    if sum(alst) < m:
        print(-1)
        return
    one = []
    two = []
    for a, b in zip(alst, blst):
        if b == 1:
            one.append(a)
        else:
            two.append(a)
    one.sort(reverse = True)
    two.sort(reverse = True)
    one = [0] + one
    two = two
    total = sum(one)
    op = len(one) - 1
    ans = float("inf")
    tp = 0
    for op in range(len(one) - 1, -1, -1):
        try:
            while total < m:
                total += two[tp]
                tp += 1
        except:
            break
        ans = min(ans, op + tp * 2)
        total -= one[op]
    print(ans)
    
for _ in range(int(input())):
    main()