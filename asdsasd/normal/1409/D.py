def main():
    t = int(input())
    for _ in range(t):
        n, s = input().split(" ")
        s = int(s)
        total = 0
        for nn in n:
            total += int(nn)
        ans = 0
        p = 1
        ten = 1
        carry = False
        while total > s:
            num = int(n[-p])
            if carry:
                num += 1
            if num == 0:
                carry = False
            else:
                ans += ten * (10 - num)
                total -= num - 1
                carry = True
            ten *= 10
            p += 1
        print(ans)
          
        
main()