a = {0: 'Zero', 1: 'One', 2: 'Two', 3: 'Three', 4: 'Four', 5: 'Five', \
    6: 'Six', 7: 'Seven', 8: 'Eight', 9: 'Nine', 10: 'Ten', \
    11: 'Eleven', 12: 'Twelve', 13: 'Thirteen', 14: 'Fourteen', \
    15: 'Fifteen', 16: 'Sixteen', 17: 'Seventeen', 18: 'Eighteen', 19: 'Nineteen'}
b = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

n = int(input())
if n < 20:
    print(a.get(n).lower())
elif n % 10 == 0:
    print(b[n//10-2].lower())
else:
    print(b[n//10-2].lower()+'-' + a.get(n % 10).lower())