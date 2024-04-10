s = raw_input()
ans = int(eval(s));
if (ans < 10):
    print('+' * (ans + 48) + '.')
elif (ans < 100):
    print('+' * (48 + ans // 10) + '.' + '>' + '+' * (ans % 10 + 48) + '.')
else:
    print('+' * (48 + ans // 100) + '.' + '>' + '+' * (48 + (ans // 10) % 10) + '.' + '>' + '+' * (48 + ans % 10) + '.')