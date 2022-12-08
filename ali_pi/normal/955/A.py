R=lambda:map(int,raw_input().split())
h,m=R()
H,D,C,N=R()
H+=N-1
print(min(H//N*C,(H+max(0,1200-h*60-m)*D)//N*C*.8))