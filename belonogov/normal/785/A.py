# a = [0, 1]
# b = []

# print(a)
# print(b)
# b.append(78)
# b.append(78)

# # a = ((a // b) * b) + (a % b)
n = int(input())
# a = [int(x) for x in input().split()]
# print(n)
# print(a)
# f=0
# a, b = [int(x) for x in input().split()]
# # a=int(input())
i=1
# print('!')
asd=0
while i<=n:
  s =input()
  if s=='Cube':
    asd=asd+6
  else:
    if s=='Tetrahedron':
      asd=asd+4
    else:
      if s=='Octahedron':
        asd=asd+8
      else:
        if s=='Dodecahedron':
          asd=asd+12
        else:
          if s=='Icosahedron':
            asd=asd+20
  i=i+1          
            

















































































































































































































































































print(asd)