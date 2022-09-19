n = int(input())
a = ['purple', 'green', 'blue', 'orange', 'red', 'yellow']
b = ['Power', 'Time', 'Space', 'Soul', 'Reality', 'Mind']
for i in range(n):
    s = input()
    i = a.index(s)
    a.pop(i)
    b.pop(i)
print(6-n)
for i in b:print(i)