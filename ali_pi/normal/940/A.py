d=int(raw_input().split()[1])
a=list(map(int,raw_input().split()))
print(min(sum(1-(0<=c-p<=d)for c in a)for p in a))