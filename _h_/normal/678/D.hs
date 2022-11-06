main=interact$show.f.map read.words
f[a,b,0,x]=x
f[a,b,n,x]=f[m$a*a,m$b*a+b,div n 2,m$if even n then x else a*x+b]
m x=mod x$10^9+7