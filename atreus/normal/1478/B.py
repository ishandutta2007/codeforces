for tc in range(int(input())):
    n,d = map(int, input().split())
    l = list(map(int, input().split()))
    dp = []
    for i in range(1000):
        if i == 0 or str(d) in str(i):
            dp.append("YES")
        else:
            for j in range(1,i):
                if str(d) in str(j) and dp[i-j] == "YES":
                    dp.append("YES")
                    break
            else:
                dp.append("NO")

    for x in l:
        if x >= 1000:
            print("YES")
        else:
            print(dp[x])