# 2 3 5 7
n=int(input())
ans=n-n//2-n//3-n//5-n//7
ans+=n//6+n//10+n//14+n//15+n//21+n//35
ans-=n//30+n//42+n//70+n//105
print(ans+n//210)