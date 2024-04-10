import sys
input = sys.stdin.readline

def main():
    n, l, r = map(int, input().split())
    clst = list(map(int, input().split()))
    left = [0] * n
    right = [0] * n
    for c in clst[:l]: left[c - 1] += 1
    for c in clst[l:]: right[c - 1] += 1
    for i in range(n):
        if left[i] > right[i]:
            left[i] -= right[i]
            right[i] = 0
        else:
            right[i] -= left[i]
            left[i] = 0
    if l > r:
        left, right = right.copy(), left.copy()
        
    ans = 0
    d = abs(l - r) // 2
    if d != 0:
        for i, r in enumerate(right):
            z = r // 2
            if z >= d:
                right[i] -= 2 * d
                break
            else:
                d -= z
    ans = (sum(left) + sum(right)) // 2 + d
    print(ans)
    
    

for _ in range(int(input())):
    main()