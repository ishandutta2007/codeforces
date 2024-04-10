def main():
    import sys
    input = sys.stdin.buffer.readline
    t = int(input())
    
    def check():
        n = int(input())
        alst = list(map(int, input().split()))
        min_a = min(alst)
        blst = []
        for a in alst:
            if a % min_a == 0:
                blst.append(a)
        pos = 0
        blst.sort()
        for i, a in enumerate(alst):
            if a % min_a == 0:
                alst[i] = blst[pos]
                pos += 1
        bef = alst[0]
        for a in alst:
            if a < bef:
                return "NO"
            bef = a
        return "YES"
        
    for _ in range(t):
        print(check())
    
main()