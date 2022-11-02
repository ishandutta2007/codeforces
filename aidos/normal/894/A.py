a = input()
ans = 0
n = len(a)
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            if a[i] + a[j] + a[k] == 'QAQ':
                ans+=1
print(ans)