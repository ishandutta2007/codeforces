def f(n):
	return (n+3)*(n+2)*(n+1)//6;
n=input();
ans=f(n);
if n>=6:ans-=f(n-6);
if n>=9:ans-=f(n-9)*2;
if n>=10:ans+=f(n-10);
if n>=14:ans+=f(n-14);
print(ans);