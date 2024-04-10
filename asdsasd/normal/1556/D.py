import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    and_ = [0] * n
    or_ = [0] * n
    xor_ = [0] * n
    for i in range(2, n + 1):
        print("or", 1, i, flush = True)
        or_[i - 1] = int(input())
        print("and", 1, i, flush = True)
        and_[i - 1] = int(input())
        xor_[i - 1] = or_[i - 1] ^ and_[i - 1]
        
    print("or", 2, 3, flush = True)
    or_23 = int(input())
    print("and", 2, 3, flush = True)
    and_23 = int(input())
    
    or_12 = or_[1]
    and_12 = and_[1]
    or_13 = or_[2]
    and_13 = and_[2]
    ans = [0] * n
    for i in range(32):
        o_12 = or_12 >> i & 1
        o_13 = or_13 >> i & 1
        o_23 = or_23 >> i & 1
        a_12 = and_12 >> i & 1
        a_13 = and_13 >> i & 1
        a_23 = and_23 >> i & 1
        if not a_12 and not o_12:
            if not o_13:
                add = [0, 0, 0]
            else:
                add = [0, 0, 1]
        elif not a_12 and o_12:
            if not a_13 and not o_13:
                add = [0, 1, 0]
            elif a_13 and o_13:
                add = [1, 0, 1]
            elif o_23:
                add = [0, 1, 1]
            else:
                add = [1, 0, 0]
        else:
            if a_13:
                add = [1, 1, 1]
            else:
                add = [1, 1, 0]
                
        for j, a in enumerate(add):
            ans[j] += a << i
            
    for i in range(3, n):
        ans[i] = ans[0] ^ xor_[i]
    ans.sort()
    
    print("finish", ans[k - 1], flush = True)
    
    
    
for _ in range(1):
    main()