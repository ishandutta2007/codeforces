import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    S = input().strip()
    cum = [0]
    for i, s in enumerate(S):
        if (s == "+") ^ (i % 2 == 1):
            cum.append(cum[-1] + 1)
        else:
            cum.append(cum[-1] - 1)

    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        d = cum[r + 1] - cum[l]
        if d == 0:
            print(0)
            continue
        elif d % 2 == 1:
            x = 1
            print(1)
        else:
            x = 2
            print(2)
            y = r
            r -= 1
            d = cum[r + 1] - cum[l]
        
        if d > 0:
            d = (d + 1) // 2
            ll = l - 1
            rr = r
            while rr - ll > 1:
                mid = (rr + ll) // 2
                if cum[mid + 1] - cum[l] >= d:
                    rr = mid
                else:
                    ll = mid
            if x == 1:
                print(rr + 1)
            else:
                print(rr + 1, y + 1)
        else:
            d = (d - 1) // 2
            ll = l - 1
            rr = r
            while rr - ll > 1:
                mid = (rr + ll) // 2
                if cum[mid + 1] - cum[l] <= d:
                    rr = mid
                else:
                    ll = mid
            if x == 1:
                print(rr + 1)
            else:
                print(rr + 1, y + 1)
        
    
for _ in range(int(input())):
    main()