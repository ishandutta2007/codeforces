from collections import *
n,a,b,c,d = list(map(int,input().split()))
print((n-min(n,max(abs(a+b-c-d),abs(b-c),abs(a-d),abs(a+c-b-d))))*n)