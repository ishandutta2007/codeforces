R=lambda:map(int,raw_input().split())
n,m=R()
print min(map(lambda v:v[0]/1./v[1],(R() for _ in range(n))))*m