q = int(input())
for _ in range(q):
    s , n = map(int , input().split())
    A = [] ; B = []
    cur = 1
    while(s):
        for i in range(s % 10):
            A.append(cur)
        cur *= 10
        s //= 10
    A.reverse()
    while(len(A) + len(B) < n):
        x = A[-1]
        A.pop()
        if(x == 1):
            B.append(x)
        else:
            for i in range(10):
                A.append(x // 10)
    for i in B:
        A.append(i)
    while(len(A) > n):
        x = A[-1] ; y = A[-2]
        A.pop(); A.pop()
        A.append(x + y)
    for i in A:
        print(i , end = " ")
    print()