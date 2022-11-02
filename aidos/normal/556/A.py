
n = int(input())
s = list(input())
ans = []
for i in s:
    if len(ans) > 0 and ans[-1] != i:
       ans.pop(-1)
    else:
        ans.append(i)

print(len(ans))