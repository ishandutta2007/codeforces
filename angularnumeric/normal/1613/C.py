import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n,h=map(int,input().split())
    A=list(map(int,input().split()))

    MIN=0
    MAX=int(1e18)

    while MIN!=MAX:
        x=(MIN+MAX)//2

        ANS=0
        for i in range(n):
            if i==0:
                ANS+=x
            else:
                ANS+=min(x,A[i]-A[i-1])

        if ANS>=h:
            MAX=x
        else:
            MIN=x+1

    print(MIN)