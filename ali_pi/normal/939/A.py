n, f = int(raw_input()), [1] + list(map(int, raw_input().split()))
print('YES' if any(f[f[f[i]]] == i for i in range(1, n + 1)) else 'NO')