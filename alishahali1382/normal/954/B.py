n=int(input())
s=input()
mid=n//2
while s[:mid]!=s[mid:2*mid] and mid!=0:
    mid-=1
print(min(n,n-mid+1))