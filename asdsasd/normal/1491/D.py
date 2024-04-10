import sys
input = sys.stdin.readline

def main():
    u, v = map(int, input().split())
    if u > v:
        print("NO")
        return
    elif u == v:
        print("YES")
        return
    elif u & v == v:
        print("NO")
        return
    
    u_cnt = 0
    v_cnt = 0
    while u or v:
        if u % 2 == 1: u_cnt += 1
        if v % 2 == 1: v_cnt += 1
        if v_cnt > u_cnt:
            print("NO")
            return
        
        u //= 2
        v //= 2
    print("YES")
    
    
for _ in range(int(input())):
    main()