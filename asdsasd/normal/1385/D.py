import sys
input = sys.stdin.readline

bin_s = [1]
alpha = "abcdefghijklmnopqrstu"

for _ in range(17):
    bin_s.append(bin_s[-1] * 2)

def main():
    import itertools
    
    n = int(input())
    S = input().strip()
    if n == 1:
        if S == "a":
            print(0)
        else:
            print(1)
        return
    k = bin_s.index(n)
    band = n // 2
    cnt = 2
    lst = []
    for i in range(k + 1):
        tmp = []
        for j in range(cnt):
            tmp.append(band - S[j * band:(j + 1) * band].count(alpha[i]))
        lst.append(tmp)
        if band != 1:
            band //= 2
            cnt *= 2
    ans = n
    
    for tf_s in itertools.product([True, False], repeat = k):
        ans_sub = 0
        pos = 0
        for i, tf in enumerate(tf_s):
            if i != k - 1:
                if tf:
                    ans_sub += lst[i][pos + 1]
                    pos *= 2
                else:
                    ans_sub += lst[i][pos]
                    pos += 1
                    pos *= 2
            else:
                if tf:
                    ans_sub += lst[i][pos + 1] + lst[i + 1][pos]
                else:
                    ans_sub += lst[i][pos] + lst[i + 1][pos + 1]
        ans = min(ans, ans_sub)
    
    print(ans)

for _ in range(int(input())):
    main()