n=int(input())
s=input()
pw=[1]
last=1
for i in range(70):
    if (last>1e19):
        break
    pw.append(last*n)
    last=last*n
dp=[1e19]*100
for i in range(100):
    dp[i]=[1e19]*100
dp[len(s)][0]=0
for i in range(len(s),-1,-1):
    for power in range(0,len(pw)):
        cur=''
        for j in range(i-1,-1,-1):
            cur=s[j]+cur
            if (int(cur)>n or int(cur)*pw[power]>1e19):
                break;
            if ((cur[0]!='0' or len(cur)==1) and int(cur)<n):
                dp[j][power+1]=min(dp[j][power+1],dp[i][power]+int(cur)*pw[power])
print(min(dp[0]))