def main():
    n = int(input())
    k = int(input())

    if k == 0:
        print(0)
        return
    
    ans = 0
    np = 1
    
    while k > 0:
        i = 10
        ok = k
        p10 = 1
        x = 0
        while ok > 0:
            c = ok % 10
            x += p10 * c
            p10 *= 10
            if x >= n:
                break
            if c != 0:
                i = p10
            ok //= 10
            
        x = k % i
        k //= i
        ans += x * np
        np *= n

    print(ans)

main()