import sys
input = sys.stdin.readline

def main():
    n, m, k = map(int, input().split())
    half = m // 2
    se_s = []
    for i in range(n):
        lst = list(map(int, input().split()))
        lst.sort(reverse = True)
        total_sub = sum(lst[:half])
        dp = [[0 for _ in range(k)] for _ in range(half + 1)]
        for num2 in lst:
            for i in range(half, 0, -1):
                for num in dp[i - 1]:
                    pos = (num + num2) % k
                    dp[i][pos] = max(dp[i][pos], num + num2)
        se_s.append(set(dp[-1]))
    
    ans = 0
    ans_sub = set([0])
    for se in se_s:
        se_tmp = set()
        for num in se:
            for num2 in ans_sub:
                se_tmp.add(num + num2)
                if (num + num2) % k == 0:
                    ans = max(ans, num + num2)
        tmp = [0 for _ in range(k)]
        for num in se_tmp:
            tmp[num % k] = max(tmp[num % k], num)
        ans_sub = set(tmp)
        
    print(ans)
                
    
main()