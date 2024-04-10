n = input()
A = [int(x) for x in raw_input().split()]
print(max([min([x - 1, 10**6 - x]) for x in A]))